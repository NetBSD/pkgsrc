#!@AWK@ -f
# $NetBSD: create-report-html.awk,v 1.15 2014/05/14 14:45:26 abs Exp $
#
# Copyright (c) 2007, 2008 Joerg Sonnenberger <joerg@NetBSD.org>.
# All rights reserved.
#
# This code was developed as part of Google's Summer of Code 2007 program.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
# COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
# AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
# OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.

function sort(ARRAY, INDICES, OPTIONS, i, idx, sort_cmd) {
	sort_cmd = "sort " OPTIONS " > " tmp_sort

	for (idx in ARRAY)
		print idx | sort_cmd
	close(sort_cmd)
	i = 0
	while ((getline < tmp_sort) > 0) {
		INDICES[i] = $0
		++i
	}
	close(tmp_sort)
	system("rm " tmp_sort)
}

function print_failed_log_line(PKGNAME, PHASE, VAR) {
	if (VAR == 1)
		printf("<td><a href=\"../%s/%s.log\">%s</a></td>\n",
		    PKGNAME, PHASE, PHASE) > html_report
	else
		print "<td>&nbsp;</td>" > html_report
}

function print_pre_fail_reason(PKGNAME, chars, in_quote, in_sep, i) {
	split(pre_fail_reason[PKGNAME], chars, "")
	in_quote = 0
	in_sep = 0
	for (i = 1; i < length(pre_fail_reason[PKGNAME]); ++i) {
		if (chars[i] == "\"") {
			in_quote = 1 - in_quote
			continue
		}
		if (in_quote == 0 && chars[i] == " ") {
			if (!in_sep)
				printf "<br />" > html_report
			in_sep = 1
			continue
		}
		in_sep = 0

		if (chars[i] == "\\") {
			++i
			if (chars[i] == "n")
				printf " " > html_report
			else if (chars[i] == "t")
				printf " " > html_report
			else if (chars[i] == "<")
				printf "&lt;" > html_report
			else if (chars[i] == ">")
				printf "&gt;" > html_report
			else if (chars[i] == "&")
				printf "&amp;" > html_report
			else
				printf "%s", chars[i] > html_report
			continue
		}
		printf "%s", chars[i] > html_report
	}
	printf "\n" > html_report
}

function print_failed(PKGNAME, cmd, has_pre_clean, has_depends,
    has_checksum,has_configure, has_build, has_install, has_package,
    has_clean, has_deinstall, last_error) {
	if (status[PKGNAME] == "failed") {
		cmd = "ls " log_dir "/" PKGNAME " 2>/dev/null"
		while ((cmd | getline) > 0) {
			if ($0 == "pre-clean.log")
				has_pre_clean = 1
			else if ($0 == "depends.log")
				has_depends = 1
			else if ($0 == "checksum.log")
				has_checksum = 1
			else if ($0 == "configure.log")
				has_configure = 1
			else if ($0 == "build.log")
				has_build = 1
			else if ($0 == "install.log")
				has_install = 1
			else if ($0 == "package.log")
				has_package = 1
			else if ($0 == "clean.log")
				has_clean = 1
			else if ($0 == "deinstall.log")
				has_deinstall = 1
		}
		close(cmd)

		if (has_deinstall)
			last_error = "deinstall.log"
		else if (has_clean)
			last_error = "clean.log"
		else if (has_package)
			last_error = "package.log"
		else if (has_install)
			last_error = "install.log"
		else if (has_build)
			last_error = "build.log"
		else if (has_configure)
			last_error = "configure.log"
		else if (has_checksum)
			last_error = "checksum.log"
		else if (has_depends)
			last_error = "depends.log"
		else if (has_pre_clean)
			last_error = "pre-clean.log"
	}
	print "<tr class=\"" status[PKGNAME] "\">" > html_report
	if (last_error)
		print "<td><a href=\"../" PKGNAME "/" last_error "\"> " location[PKGNAME] "</a></td>" > html_report
	else
		print "<td>" location[PKGNAME] "</td>" > html_report
	print "<td>" PKGNAME "</td>" > html_report
	if (depth[PKGNAME] == 0)
		print "<td>&nbsp;</td>" > html_report
	else
		print "<td>" depth[PKGNAME] "</td>" > html_report
	print "<td>" maintainer[PKGNAME] "</td>" > html_report
	print "<td>" status[PKGNAME] "</td>" > html_report
	print_failed_log_line(PKGNAME, "pre-clean", has_pre_clean)
	print_failed_log_line(PKGNAME, "depends", has_depends)
	print_failed_log_line(PKGNAME, "checksum", has_checksum)
	print_failed_log_line(PKGNAME, "configure", has_configure)
	print_failed_log_line(PKGNAME, "build", has_build)
	print_failed_log_line(PKGNAME, "install", has_install)
	print_failed_log_line(PKGNAME, "package", has_package)
	print_failed_log_line(PKGNAME, "clean", has_clean)
	print_failed_log_line(PKGNAME, "deinstall", has_deinstall)
	print "</tr>" > html_report
	if (status[PKGNAME] == "indirect-failed") {
		print "<tr class=\"" status[PKGNAME] "\">" > html_report
		printf "<td>&nbsp;</td>" > html_report
		printf "<td colspan=\"13\"> Failed: " > html_report
		printf "%s", failed_pkgs[PKGNAME] > html_report
		print "</td>" > html_report
		print "</tr>" > html_report
	}
	if (status[PKGNAME] == "prefailed") {
		print "<tr class=\"" status[PKGNAME] "\">" > html_report
		printf "<td>&nbsp;</td>" > html_report
		printf "<td colspan=\"13\">" > html_report
		print_pre_fail_reason(PKGNAME)
		print "</td>" > html_report
		print "</tr>" > html_report
	}
}

function compute_direct_failure(CUR, dep, cur_dep, cur_depends, found, i) {
	if (failed_pkgs[CUR] != "")
		return
	split(depends[CUR], cur_depends, "[ \t]+")
	for (dep in cur_depends) {
		cur_dep = cur_depends[dep]
		if (status[cur_dep] == "failed") {
			failed_pkgs[CUR] = failed_pkgs[CUR] " " cur_dep
		} else if (status[cur_dep] == "indirect-failed") {
			compute_direct_failure(cur_dep)
			failed_pkgs[CUR] = failed_pkgs[cur_dep] " " failed_pkgs[CUR]
		}
	}
	split(failed_pkgs[CUR], cur_depends, "[ \t]+")
	failed_pkgs[CUR] = ""
	for (dep in cur_depends) {
		cur_dep = cur_depends[dep]
		found[cur_dep] = 1
	}
	i = 0
	for (dep in found) {
		if (++i == 10) {
			failed_pkgs[CUR] = failed_pkgs[CUR] " ..."
			break;
		}
		failed_pkgs[CUR] = failed_pkgs[CUR] " " dep
	}
}

BEGIN {
	meta_dir = ARGV[1]
	log_dir = ARGV[2]
	report_file = meta_dir "/report"
	html_report = meta_dir "/report.html"
	status_file = meta_dir "/status"
	tmp_sort = meta_dir "/tmp_sort"

	pkgs_done = 0
	pkgs_failed = 0
	pkgs_prefailed = 0
	pkgs_indirect_failed = 0
	pkgs_indirect_prefailed = 0

	while ((getline < status_file) > 0) {
		if ($0 ~ "^PLATFORM=")
			pkgsrc_platform = substr($0, 10)
		else if ($0 ~ "^COMPILER=")
			pkgsrc_compiler = substr($0, 10)
		else if ($0 ~ "^BUILD_START_ISO=")
			pkgsrc_build_start_iso = substr($0, 17)
		else if ($0 ~ "^BUILD_END_ISO=")
			pkgsrc_build_end_iso = substr($0, 15)
	}
	close(status_file)

	while ((getline < report_file) > 0) {
		if ($0 ~ "^PKGNAME=")
			cur = substr($0, 9)
		else if ($0 ~ "^MAINTAINER=")
			maintainer[cur] = substr($0, 12)
		else if ($0 ~ "^PKG_LOCATION=")
			location[cur] = substr($0, 14)
		else if ($0 ~ "^PKG_DEPTH=")
			depth[cur] = substr($0, 11) - 1
		else if ($0 ~ "^BUILD_STATUS=")
			status[cur] = substr($0, 14)
		else if ($0 ~ "^PKG_FAIL_REASON=")
			pre_fail_reason[cur] = substr($0, 17)
		else if ($0 ~ "^DEPENDS=")
			depends[cur] = substr($0, 9)
	}
	close(report_file)

	for (pkg in status) {
		if (status[pkg] == "done")
			++pkgs_done
		else if (status[pkg] == "failed")
			++pkgs_failed
		else if (status[pkg] == "prefailed")
			++pkgs_prefailed
		else if (status[pkg] == "indirect-failed") {
			compute_direct_failure(pkg)
			++pkgs_indirect_failed
		} else if (status[pkg] == "indirect-prefailed")
			++pkgs_indirect_prefailed
	}

	print "<html>" > html_report
	print "  <head>" > html_report
	printf("    <title> pkgsrc bulk build for %s from %s</title>\n",
	    pkgsrc_platform, pkgsrc_build_start_iso) > html_report
	print "  </head>" > html_report
	print "  <body>" > html_report
	printf("    <h1> pkgsrc bulk build for %s</h1>\n", pkgsrc_platform) > html_report
	printf("    <h2> Build start: %s</h2>\n", pkgsrc_build_start_iso) > html_report
	printf("    <h2> Build end: %s</h2>\n", pkgsrc_build_end_iso) > html_report
	print "    <hr />" > html_report

	all_pkgs = pkgs_done + pkgs_failed + pkgs_prefailed + pkgs_indirect_failed + pkgs_indirect_prefailed

	print "    <table>" > html_report
	printf("      <tr><td>Total number of packages:</td><td>%d</td></tr>\n", all_pkgs) > html_report
	printf("      <tr><td>Successfully built:</td><td>%d</td></tr>\n", pkgs_done) > html_report
	printf("      <tr><td>Failed build:</td><td>%d</td></tr>\n", pkgs_failed) > html_report
	printf("      <tr><td>Depending on failed package:</td><td>%d</td></tr>\n", pkgs_indirect_failed) > html_report
	printf("      <tr><td>Explicitly broken or masked:</td><td>%d</td></tr>\n", pkgs_prefailed) > html_report
	printf("      <tr><td>Depending on masked package:</td><td>%d</td></tr>\n", pkgs_indirect_prefailed) > html_report
	print "    </table>" > html_report
	print "    <hr />" > html_report

	has_top_count = 0
	for (pkg in status) {
		if (depth[pkg] == 0 || status[pkg] != "failed")
			continue
		top_count[depth[pkg] " " pkg] = pkg
		has_top_count = 1
	}
	if (has_top_count) {
		sort(top_count, sorted_top_count, "-rn")
		print "    <h2>Packages causing the most breakage</h2>" > html_report
		print "    <table>" > html_report
		print "      <thead>" > html_report
		print "        <tr>" > html_report
		print "          <th> Location </th>" > html_report
		print "          <th> Package </th>" > html_report
		print "          <th> Breaks </th>" > html_report
		print "          <th> Maintainer </th>" > html_report
		print "          <th> Status </th>" > html_report
		print "          <th colspan=\"9\"> Build log </th>" > html_report
		print "        </tr>" > html_report
		print "      </thead>" > html_report
		print "      <tbody>" > html_report

		for (i = 0; i < 10 && sorted_top_count[i] != ""; ++i) {
			pkg = top_count[sorted_top_count[i]]
			print_failed(pkg)
		}

		print "      </tbody>" > html_report
		print "    </table>" > html_report
		print "    <hr />" > html_report
	}

	print "    <h2> All unsuccessful builds </h2>" > html_report

	print "    <table>" > html_report
	print "      <thead>" > html_report
	print "        <tr>" > html_report
	print "          <th> Location </th>" > html_report
	print "          <th> Package </th>" > html_report
	print "          <th> Breaks </th>" > html_report
	print "          <th> Maintainer </th>" > html_report
	print "          <th> Status </th>" > html_report
	print "          <th colspan=\"9\"> Build log </th>" > html_report
	print "        </tr>" > html_report
	print "      </thead>" > html_report
	print "      <tbody>" > html_report

	for (pkg in status)
		loc_pkg_array[location[pkg] " " pkg] = pkg

	sort(loc_pkg_array, sorted_loc_pkg_array, "")

	for (i = 0; sorted_loc_pkg_array[i] != ""; ++i) {
		pkg = loc_pkg_array[sorted_loc_pkg_array[i]]
		if (status[pkg] == "done")
			continue
		print_failed(pkg)
	}

	print "      </tbody>" > html_report
	print "    </table>" > html_report
	print "  </body>" > html_report
	print "</html>" > html_report
}
