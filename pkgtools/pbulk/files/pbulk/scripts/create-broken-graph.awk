#!@AWK@ -f -
# $NetBSD: create-broken-graph.awk,v 1.1.1.1 2007/06/19 19:49:59 joerg Exp $
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

BEGIN {
	meta_dir = ARGV[1]
	report_file = meta_dir "/report"
	graph_file = meta_dir "/report.dot"

	while ((getline < report_file) > 0) {
		if ($0 ~ "^PKGNAME=")
			cur = substr($0, 9)
		else if ($0 ~ "^DEPENDS=")
			depends[cur] = substr($0, 9)
		else if ($0 ~ "^PKG_DEPTH=")
			depth[cur] = substr($0, 11) - 1
		else if ($0 ~ "^BUILD_STATUS=")
			status[cur] = substr($0, 14)
	}
	close(report_file)

	print "digraph \"Broken packages\" {" > graph_file
	for (pkg in depends) {
		split(depends[pkg], depend_list, "[ \t]+")

		for (dep in depend_list) {
			cur_pkg = depend_list[dep]
			if (status[cur_pkg] != "failed" &&
			    status[cur_pkg] != "prefailed" &&
			    status[cur_pkg] != "indirect-failed" &&
			    status[cur_pkg] != "indirect-prefailed")
				continue;
			if (status[cur_pkg] == "failed")
				color = "red"
			else
				color = "lightgray"
			printf("\"%s\" -> \"%s\" [ color = \"%s\" ];\n", cur_pkg, pkg, color) > graph_file
			drawn_pkgs[cur_pkg] = 1
			drawn_pkgs[pkg] = 1
		}
	}
	for (pkg in status) {
		if (status[pkg] != "failed" &&
		    status[pkg] != "prefailed" &&
		    status[pkg] != "indirect-failed" &&
		    status[pkg] != "indirect-prefailed")
			continue;

		if (depth[pkg] == 0 && !(pkg in drawn_pkgs))
			continue;

		if (status[pkg] == "failed")
			color = "red"
		else if (status[pkg] == "prefailed")
			color = "gray2"
		else if (status[pkg] == "indirect-failed")
			color = "orange"
		else if (status[pkg] == "indirect-prefailed")
			color = "lightgray"
		printf("\"%s\" [ color = \"%s\", fontcolor = \"%s\", label=\"%s\" ];\n", pkg, color, color, pkg) > graph_file
	}
	print "}" > graph_file
}
