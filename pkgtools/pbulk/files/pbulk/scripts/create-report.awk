#!@AWK@ -f -
# $NetBSD: create-report.awk,v 1.1.1.1 2007/06/19 19:49:59 joerg Exp $
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
	pbuild_file = meta_dir "/pbuild"
	presolve_file = meta_dir "/presolve"
	full_pbuild_file = meta_dir "/report"

	FS = "|"
	while ((getline < pbuild_file) > 0) {
		status[$1] = $2
		restricted[$1] = $3
		depth[$1] = $4
	}
	close(pbuild_file)

	FS = ""

	while ((getline < presolve_file) > 0) {
		if ($0 ~ "^PKGNAME=") {
			cur = substr($0, 9)
			pkg[cur] = $0
		} else {
			pkg[cur] = pkg[cur] "\n" $0
		}

		if ($0 ~ "^MAINTAINER=")
			maintainer[cur] = substr($0, 12)

		if ($0 ~ "^PKG_LOCATION=") {
			loc = substr($0, 14)
			location[cur] = loc

			if (status[cur] == "failed") {
				broken_location[loc] += depth[cur]
				pkg_location[loc] = cur
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
		}
	}
	close(presolve_file)

	printf "" > full_pbuild_file

	for (p in pkg) {
		print pkg[p] > full_pbuild_file
		print "PKG_DEPTH=" depth[p] > full_pbuild_file
		if (restricted[p] == "restricted")
			print "RESTRICTED_SUBSET=yes" > full_pbuild_file
		else
			print "RESTRICTED_SUBSET=no" > full_pbuild_file
		print "BUILD_STATUS=" status[p] > full_pbuild_file
	}
	close full_pbuild_file
}
