#!/usr/bin/awk -f
#
# $NetBSD: depends-depth-first.awk,v 1.7 2018/08/22 20:48:37 maya Exp $
#
# Copyright (c) 2006 The NetBSD Foundation, Inc.
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
#	depends-depth-first.awk -- traverse the dependency graph
#
# SYNOPSIS
#	depends-depth-first.awk -- [options] pkgpath ...
#
# DESCRIPTION
#	depends-depth-first.awk performs a depth-first traversal of the
#	dependency graph associated with the package directories specified
#	on the command line, and provides a hook to allow a shell command
#	line to be executed within each package directory during traversal.
#
# OPTIONS
#	The following command line arguments are supported.
#
#	--		This is a mandatory option and must always be the
#			first option specified.
#
#	-c cmdline	Execute the specified command line when visiting
#			a package directory during traversal.  If the -c
#			option is not given, then the default action is
#			to output the package directory name.
#
#	-d depends-type
#			When searching for a package's dependencies, use
#			the named "depends-type".  This is passed as the
#			DEPENDS_TYPE argument of the "show-depends-pkgpaths"
#			target.  By default, the dependency type is "all".
#
#	-o order	The dependencies are visited during the dependency
#			graph traversal in the named order, which is either
#			"prefix" or "postfix".  By default, dependencies
#			are visited in "postfix" order.
#
#	-r		If the -r option is specified, then the package
#			directories specified on the command-line are
#			also visited.
#
#	-s pkgsrcdir	Use the specified directory as the path to the
#			pkgsrc directory tree.  By default, this is the
#			value stored in the PKGSRCDIR environment variable.
#
# ENVIRONMENT
#	MAKEFLAGS	This contains the shell environment in the format
#			required by make(1) that is passed to the process
#			that outputs a package's dependencies.
#
#	PKGSRCDIR	This is the location of the pkgsrc directory tree,
#			which defaults to "/usr/pkgsrc".
#
######################################################################

######################################################################
#
# Initialize global variables, parse the command-line arguments, and
# invoke the main() function
#
######################################################################
BEGIN {
	ECHO = ENVIRON["ECHO"] ? ENVIRON["ECHO"] : "echo"
	MAKE = ENVIRON["MAKE"] ? ENVIRON["MAKE"] : "make"
	PKGSRCDIR = ENVIRON["PKGSRCDIR"] ? ENVIRON["PKGSRCDIR"] : "/usr/pkgsrc"
	TEST = ENVIRON["TEST"] ? ENVIRON["TEST"] : "test"

	self = "depends-depth-first.awk"
	cmd_hook = ""
	depends_type = "all"
	do_root = 0
	walk_order = "postfix"

	ARGSTART = 1
	parse_options()
	main()
}

######################################################################
#
# usage()
#	Output the usage message to standard error.
#
######################################################################
function usage() {
	print "usage: " self " [-- [-c cmdline] [-d depends-type] [-o order] [-r] [-s pkgsrcdir]] [pkgpath ...]" > "/dev/stderr"
}

######################################################################
#
# parse_options()
#	Adjust global variables based on the options passed on the
#	command line.  After this function exists, ARGSTART is set
#	to the index in the ARGV array of the first package directory
#	in which to begin the traversal.
#
######################################################################
function parse_options(		option) {
	if (ARGV[ARGSTART] == "--") {
		ARGSTART++
	}
	while (ARGSTART < ARGC) {
		option = ARGV[ARGSTART]
		if (option == "-c") {
			cmd_hook = ARGV[ARGSTART + 1]
			ARGSTART += 2
		} else if (option == "-d") {
			depends_type = ARGV[ARGSTART + 1]
			ARGSTART += 2
		} else if (option == "-o") {
			walk_order = ARGV[ARGSTART + 1]
			ARGSTART += 2
		} else if (option == "-r") {
			do_root = 1
			ARGSTART++
		} else if (option == "-s") {
			PKGSRCDIR = ARGV[ARGSTART + 1]
			ARGSTART += 2
		} else if (option == "--") {
			ARGSTART++
			break;
		} else if (match(option, /^-.*/) != 0) {
			option = substr(option, RSTART + 1, RLENGTH)
			print self ": unknown option -- " option > "/dev/stderr"
			usage()
			exit 1
		} else {
			ARGSTART++
		}
	}
	if (walk_order !~ /prefix|postfix/) {
		print self ": unknown walk order -- " walk_order > "/dev/stderr"
		usage()
		exit 1
	}
}

######################################################################
#
# main()
#	This provides an implementation of the well-known non-recursive
#	algorithm for depth-first-traversal of a graph, but with a
#	small modification to allow visiting the nodes (package directories)
#	in either "prefix" or "postfix" order.  This more closely mimics
#	a function stack than the usual non-recursive DFS algorithm.
#
######################################################################
function main(		cmd, depends_pkgpath, dir, pkgpath) {
	#
	# Push the given package directories onto the stack.
	while (ARGC >= ARGSTART) {

		ARGC--;
		cmd = TEST " -d " PKGSRCDIR "/" ARGV[ARGC]
		if (system(cmd) == 0) {
			if (do_root == 0) {
				root[ARGV[ARGC]] = ARGV[ARGC]
			}
			if (status[ARGV[ARGC]] == "") {
				push(dir_stack, ARGV[ARGC])
			}
		}

		# Depth-first traversal of dependency graph.
		while (!empty(dir_stack)) {
			pkgpath = top(dir_stack)

			if (status[pkgpath] != "") {
				if (walk_order == "postfix" && status[pkgpath] != "visited") {
					status[pkgpath] = "visited"
					visit(pkgpath)
				}
				pop(dir_stack)
				continue
			}

			status[pkgpath] = "walked"

			if (walk_order == "prefix" && status[pkgpath] != "visited") {
				status[pkgpath] = "visited"
				visit(pkgpath)
			}

			# Grab the "depends_type" dependencies of the current
			# package and push them onto the stack.  We use the
			# "show-depends-pkgpaths" target to fetch this information.
			#
			dir = PKGSRCDIR "/" pkgpath
			cmd = "if " TEST " -d " dir "; then cd " dir " && " MAKE " show-depends-pkgpaths DEPENDS_TYPE=\"" depends_type "\"; fi"
			while (cmd | getline depends_pkgpath) {
				if (status[depends_pkgpath] == "") {
					push(tmp_stack, depends_pkgpath)
				}
			}
			close(cmd)
			# This isn't really necessary, but does preserve child traversal
			# order as presented by show-depends-pkgpaths
			while (!empty(tmp_stack)) {
				push(dir_stack, top(tmp_stack))
				pop(tmp_stack)
			}
		}
	}
	exit 0
}

######################################################################
#
# visit(pkgpath)
#	Visit the package directory by running the shell command
#	specified on the command line and stored in "cmd_hook".
#	If "cmd_hook" is empty, then just print the package directory
#	name.
#
######################################################################
function visit(pkgpath,		cmd, dir) {
	if ((do_root == 0) && (root[pkgpath] != "")) {
		return
	}
	if (cmd_hook == "") {
		print pkgpath
	} else {
		dir = PKGSRCDIR "/" pkgpath
		cmd = "cd " dir " && " cmd_hook
		system(cmd)
	}
}

######################################################################
#
# empty(stack)
# top(stack)
# push(stack, element)
# pop(stack)
#	The well-known functions associated with a STACK.
#
######################################################################
function empty(stack) {
	return (stack[0] <= 0)
}

function top(stack) {
	return stack[stack[0]];
}

function push(stack, elt) {
	stack[++stack[0]] = elt
}

function pop(stack) {
	stack[0]--
}
