#!@AWK@ -f -
# $NetBSD: create-report-txt.awk,v 1.1.1.1 2007/06/19 19:49:59 joerg Exp $
#
# Copyright (c) 2007 Joerg Sonnenberger <joerg@NetBSD.org>.
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
	close sort_cmd
	i = 0
	while ((getline < tmp_sort) > 0) {
		INDICES[i] = $0
		++i
	}
	close tmp_sort
	system("rm " tmp_sort)
}

function format_time(FORMAT, TIME, format_cmd) {
	format_cmd = sprintf("date -r %d \"+%s\"", TIME, FORMAT)
	format_cmd | getline
	close format_cmd
	return $0
}

BEGIN {
	meta_dir = ARGV[1]
	report_file = meta_dir "/report"
	txt_report = meta_dir "/report.txt"
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
		else if ($0 ~ "^BUILD_START=")
			pkgsrc_build_start = substr($0, 13)
		else if ($0 ~ "^BUILD_END=")
			pkgsrc_build_end = substr($0, 11)
		else if ($0 ~ "^BASE_URL=")
			pkgsrc_base_url = substr($0, 10)
	}
	close status_file

	while ((getline < report_file) > 0) {
		if ($0 ~ "^PKGNAME=")
			cur = substr($0, 9)
		else if ($0 ~ "^MAINTAINER=")
			maintainer[cur] = substr($0, 12)
		else if ($0 ~ "^PKG_LOCATION=")
			location[cur] = substr($0, 14)
		else if ($0 ~ "^PKG_DEPTH=")
			depth[cur] = substr($0, 11) - 1
		else if ($0 ~ "^BUILD_STATUS=") {
			status[cur] = substr($0, 14)
		}
	}
	close(report_file)

	for (pkg in status) {
		loc = location[pkg]
		if (status[pkg] == "failed") {
			broken_location[loc] += depth[pkg]
			pkg_location[loc] = pkg
			if (location_status[loc] == "")
				location_status[loc] = "failed"
			else if (location_status[loc] == "ignore")
				location_status[loc] = "mixed"
		} else {
			if (location_status[loc] == "failed")
				location_status[loc] = "mixed"
			else if (location_status[loc] == "")
				location_status[loc] = "ignore"
		}

		if (status[pkg] == "done")
			++pkgs_done
		else if (status[pkg] == "failed")
			++pkgs_failed
		else if (status[pkg] == "prefailed")
			++pkgs_prefailed
		else if (status[pkg] == "indirect-failed")
			++pkgs_indirect_failed
		else if (status[pkg] == "indirect-prefailed")
			++pkgs_indirect_prefailed
	}

	print "pkgsrc bulk build report" > txt_report
	print "========================" > txt_report
	print "" > txt_report
	print pkgsrc_platform > txt_report
	print "Compiler: " pkgsrc_compiler > txt_report
	print "" > txt_report	
	print "Build start: " format_time("%F %R", pkgsrc_build_start) > txt_report
	print "Build end:   " format_time("%F %R", pkgsrc_build_end) > txt_report
	print "" > txt_report
	report_base_url = pkgsrc_base_url format_time("/%Y%m%d.%H%M", pkgsrc_build_start)
	print "Full report: " report_base_url "/meta/report.html" > txt_report
	print "Machine readable version: " report_base_url "/meta/report.bz2" > txt_report
	print "" > txt_report
	all_pkgs = pkgs_done + pkgs_failed + pkgs_prefailed + pkgs_indirect_failed + pkgs_indirect_prefailed
	printf "Total number of packages:      %5d\n", all_pkgs > txt_report
	printf "  Succesfully built:           %5d\n", pkgs_done > txt_report
	printf "  Failed to build:             %5d\n", pkgs_failed > txt_report
	printf "  Depending on failed package: %5d\n", pkgs_indirect_failed > txt_report
	printf "  Explictly broken or masked:  %5d\n", pkgs_prefailed > txt_report
	printf "  Depending on masked package: %5d\n", pkgs_indirect_prefailed > txt_report
	print "" > txt_report

	for (loc in location_status) {
		if (broken_location[loc] != "" && broken_location[loc] != 0)
			top_count[broken_location[loc] " " loc] = loc
	}
	sort(top_count, sorted_top_count, "-rn")
	if (sorted_top_count[0]) {
		print "Most offending build failures" > txt_report
		print "" > txt_report
		print "Package                               Breaks Maintainer" > txt_report
		print "-------------------------------------------------------------------------" > txt_report
		for (i = 0; i < 10 && sorted_top_count[i] != ""; ++i) {
			loc = top_count[sorted_top_count[i]]
			printf "%- 37s % 6d %s\n", loc, broken_location[loc],
			    maintainer[pkg_location[loc]] > txt_report
		}
		print "" > txt_report
	}
	print "Build failures" > txt_report
	print "" > txt_report
	print "Package                               Breaks Maintainer" > txt_report
	print "-------------------------------------------------------------------------" > txt_report

	sort(location_status, sorted_loc, "")

	for (i = 0; sorted_loc[i] != ""; ++i) {
		loc = sorted_loc[i]

		if (location_status[loc] == "ignore")
			continue

		if (broken_location[loc] == 0)
			printf "%- 44s %s\n", loc,
			    maintainer[pkg_location[loc]] > txt_report
		else
			printf "%- 37s % 6d %s\n", loc, broken_location[loc],
			    maintainer[pkg_location[loc]] > txt_report

		if (location_status[loc] != "mixed")
			continue
		for (p in status) {
			if (location[p] != loc || status[p] != "failed")
				continue
			if (depth[p] == 0)
				printf "    %- 40s %s\n", p, maintainer[p] > txt_report
			else
				printf "    %- 33s % 6d %s\n", p, depth[p], maintainer[p] > txt_report
		}
	}
	close txt_report
}
