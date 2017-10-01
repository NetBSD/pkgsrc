#!/usr/bin/awk -f
#
# $NetBSD: reduce-depends.awk,v 1.4 2017/05/19 14:58:51 joerg Exp $
#
# Copyright (c) 2006-2017 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Johnny C. Lam.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#

######################################################################
#
# NAME
#	reduce-depends.awk -- reduce a list of dependencies
#
# SYNOPSIS
#	reduce-depends.awk depends-list
#
# DESCRIPTION
#	reduce-depends.awk removes some extraneous dependencies from the
#	dependency list.  The dependency list should be passed as a single
#	argument, and the output will be a list of the reduced dependencies,
#	each dependency separated by a new line.
#
#	depends-list	A whitespace-separated list of dependencies.
#			This must be passed to the script as a single
#			argument.
#
# ENVIRONMENT
#	CAT	The name or path to the cat(1) utility.
#
#	PKG_ADMIN
#		The name or path to the pkg_admin(1) utility.
#
#	PWD_CMD
#		The command to get the physical path to the current
#		working directory.  The default is "pwd -P".
#
#	TEST	The name or path to the test(1) utility.
#
######################################################################

function shquote(s)
{
	# Escape single quotes (') by replacing them with '\''.
	gsub(/'/, "'\\''", s)
	# Surround with single quotes (').
	return "'" s "'"
}

function version_cmp(v1, cmp, v2,	cmd, pattern, pkg)
{
	pkg = shquote("test-" v1)
	test_pattern = shquote("test" cmp v2)
	cmd = PKG_ADMIN " pmatch " test_pattern " " pkg
	if (system(cmd) == 0) {
		# v1 "cmp" v2
		return 1
	}
	return 0
}

function add_reduced(reduced, pattern, dir,	depend)
{
	depend = pattern ":" dir
	if (!(depend in reduced)) reduced[depend] = depend
}

###
# get_endpoint(cmp, patterns)
#
# Parameters:
#	cmp (string)
#		The relational operator ("<", "<=", ">", ">=").
#
#	patterns (array)
#		The keys of the array form the set of dependency
#		patterns that need to be reduced to a single pattern.
#		The patterns all use the relational operator (cmp)
#		and each expresses a ray of version strings.
#
# Return value:
#	endpoint (string)
#		The endpoint for the ray of version strings.
#
# Description:
#	Returns a version string that is the endpoint of the ray of
#	version strings formed from the intersection of the rays
#	expressed by the patterns listed in the patterns array.
#
function get_endpoint(cmp, patterns, 	endpoint, key, match_all, pattern, pkg)
{
	endpoint = ""			# return value if patterns array is empty
	for (key in patterns) {
		endpoint = patterns[key]
		pkg = shquote(gensub(cmp, "-", 1, key))
		match_all = 1
		for (pattern in patterns) {
			if (key == pattern) continue
			# Fix up the pattern to be closed if it is open.
			if (cmp == "<")		sub("<", "<=", pattern)
			else if (cmp == ">")	sub(">", ">=", pattern)
			cmd = PKG_ADMIN " pmatch " shquote(pattern) " " pkg
			if (system(cmd) != 0) {
				match_all = 0
				break
			}
		}
		if (match_all == 1) break
	}
	return endpoint
}

BEGIN {
	CAT = ENVIRON["CAT"] ? ENVIRON["CAT"] : "cat"
	PKG_ADMIN = ENVIRON["PKG_ADMIN"] ? ENVIRON["PKG_ADMIN"] : "pkg_admin"
	PWD_CMD = ENVIRON["PWD_CMD"] ? ENVIRON["PWD_CMD"] : "pwd -P"
	TEST = ENVIRON["TEST"] ? ENVIRON["TEST"] : "test"

	PROGNAME = "reduce-depends.awk"
	ERRCAT = CAT " 1>&2"

	# Match version numbers with an ERE.
	# XXX This matches more than it should.
	VERSION_RE = "[0-9A-Za-z._+]+"

	# Gather all dependencies into the patterns array.  Index 0 of the
	# patterns[pkgpath] array is the number of patterns associated with
	# that pkgpath.
	#
	args = ARGV[1]
	ARGC = split(args, ARGV); ARGC++
	for (i = 1; i < ARGC; i++) {
		pattern = ARGV[i];	sub(":.*", "", pattern)
		dir = ARGV[i];		sub(".*:", "", dir)
		if (pattern ":" dir != ARGV[i]) {
			print "ERROR: [" PROGNAME "] invalid dependency pattern: " ARGV[i] | ERRCAT
			exit 1
		}
		if (pattern_seen[pattern] == 1) continue
		pattern_seen[pattern] = 1
		cmd = TEST " -d " shquote(dir)
		if (system(cmd) == 0) {
			cmd = "cd " shquote(dir) " && " PWD_CMD
			while ((cmd | getline pkgpath) > 0) {
				if (!(pkgpath in pkgsrcdirs)) {
					pkgpaths[P++] = pkgpath
					pkgsrcdirs[pkgpath] = dir
				}
				D = ++patterns[pkgpath, 0]
				patterns[pkgpath, D] = pattern
			}
			close(cmd)
		} else {
			print "ERROR: [" PROGNAME "] " dir " does not exist." | ERRCAT
			exit 1
		}
	}

	for (p = 0; p < P; p++) {
		pkgpath = pkgpaths[p]
		dir = pkgsrcdirs[pkgpath]
		D = patterns[pkgpath, 0]
		for (d = 1; d <= D; d++) {
			pattern = patterns[pkgpath, d]
			lt_bound = ""; le_bound = ""; ge_bound = ""; gt_bound = ""
			if (match(pattern, "<" VERSION_RE "$")) {
				lt_bound = substr(pattern, RSTART + 1, RLENGTH)
				pattern = substr(pattern, 1, RSTART - 1)
			}
			if (match(pattern, "<=" VERSION_RE "$")) {
				le_bound = substr(pattern, RSTART + 2, RLENGTH)
				pattern = substr(pattern, 1, RSTART - 1)
			}
			if (match(pattern, ">" VERSION_RE "$")) {
				gt_bound = substr(pattern, RSTART + 1, RLENGTH)
				pattern = substr(pattern, 1, RSTART - 1)
			}
			if (match(pattern, ">=" VERSION_RE "$")) {
				ge_bound = substr(pattern, RSTART + 2, RLENGTH)
				pattern = substr(pattern, 1, RSTART - 1)
			}
			base = pattern
			if (lt_bound) lt_patterns[base "<"  lt_bound] = lt_bound
			if (le_bound) le_patterns[base "<=" le_bound] = le_bound
			if (gt_bound) gt_patterns[base ">"  gt_bound] = gt_bound
			if (ge_bound) ge_patterns[base ">=" ge_bound] = ge_bound
			if (!(lt_bound || le_bound || gt_bound || ge_bound)) {
				depend = pattern ":" dir
				if (!(depend in reduced)) reduced[depend] = ++N
			} else {
				pkgbase[pkgpath] = base
			}
		}
		lt_bound = get_endpoint("<",  lt_patterns)
		le_bound = get_endpoint("<=", le_patterns)
		gt_bound = get_endpoint(">",  gt_patterns)
		ge_bound = get_endpoint(">=", ge_patterns)

		# Lower bound and relational operator.
		lower_bound = ""; gt = ""
		if (gt_bound && ge_bound) {
			if (version_cmp(gt_bound, ">=", ge_bound)) {
				lower_bound = gt_bound; gt = ">"
			} else {
				lower_bound = ge_bound; gt = ">="
			}
		} else if (gt_bound) {
			lower_bound = gt_bound; gt = ">"
		} else if (ge_bound) {
			lower_bound = ge_bound; gt = ">="
		}

		# Upper bound and relational operator.
		upper_bound = ""; lt = ""
		if (lt_bound && le_bound) {
			if (version_cmp(lt_bound, "<=", le_bound)) {
				upper_bound = lt_bound; lt = "<"
			} else {
				upper_bound = le_bound; lt = "<="
			}
		} else if (lt_bound) {
			upper_bound = lt_bound; lt = "<"
		} else if (le_bound) {
			upper_bound = le_bound; lt = "<="
		}

		# If there are conflicting dependencies, then just pass them
		# through and let the rest of the pkgsrc machinery handle it.
		#
		# Othewise, build a new dependency based on the intersection
		# of the rays determined by the various bounds.
		#
		if (lower_bound && upper_bound &&
		    ((gt == ">" && version_cmp(lower_bound, ">=", upper_bound)) ||
		     (gt == ">=" && version_cmp(lower_bound, ">", upper_bound)))) {
			for (d = 1; d <= D; d++) {
				depend = patterns[pkgpath, d] ":" dir
				if (!(depend in reduced)) reduced[depend] = ++N
			}
		} else if (lower_bound || upper_bound) {
			pattern = pkgbase[pkgpath] gt lower_bound lt upper_bound
			depend = pattern ":" dir
			if (!(depend in reduced)) reduced[depend] = ++N
		}

		delete lt_patterns
		delete le_patterns
		delete gt_patterns
		delete ge_patterns
	}

	# Output reduced dependencies.
	for (depend in reduced) output[reduced[depend]] = depend
	for (i = 1; i <= N; i++) print(output[i])
}
