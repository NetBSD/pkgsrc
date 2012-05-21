#!@AWK@ -f
# $NetBSD: compute-packages.awk,v 1.3.30.1 2012/05/21 09:48:29 tron Exp $
#
# Copyright (c) 2007, 2012 Joerg Sonnenberger <joerg@NetBSD.org>.
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

function mark_restricted(PKG, dep, depend_list) {
	if (PKG in restricted)
		return

	restricted[PKG] = 1

	split(reverse_depends[PKG], depend_list, "[ \t]+")
	for (dep in depend_list)
		mark_restricted(depend_list[dep])
}

BEGIN {
	meta_dir = ARGV[1]
	success_file = meta_dir "/success"
	presolve_file = meta_dir "/presolve"

	while ((getline < presolve_file) > 0) {
		if ($0 ~ "^PKGNAME=") {
			cur = substr($0, 9)
			pkgs[cur] = cur
		}

		if ($0 ~ "^CATEGORIES=")
			categories[cur] = substr($0, 12)

		if ($0 ~ "^BUILD_STATUS=")
			status[cur] = substr($0, 14)

		if ($0 ~ "^NO_BIN_ON_FTP=.")
			initial_restricted[cur] = 1

		if ($0 ~ "^DEPENDS=")
			depends[cur] = substr($0, 9)
	}
	close(presolve_file)

	for (pkg in depends) {
		split(depends[pkg], depend_list, "[ \t]+")
		for (dep in depend_list) {
			cur_dep = depend_list[dep]
			reverse_depends[cur_dep] = pkg " " reverse_depends[cur_dep]
		}
	}

	for (pkg in initial_restricted)
		mark_restricted(pkg)

	while ((getline pkg < success_file) > 0) {
		# skip restricted packages
		if (pkg in restricted)
			continue;
		# build category/file list
		split(categories[pkg], cats, "[ \t]+")
		cats[0] = "All"
		for (cat_idx in cats) {
			cat = cats[cat_idx]
			if (!(cat in printed_cats)) {
				print "+ " cat "/"
				printed_cats[cat] = cat
			}
			print "+ " cat "/" pkg ".tgz"
		}
	}
	close(success_file)
}
