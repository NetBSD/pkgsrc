# $NetBSD: opt-version.mk,v 1.2 2024/09/17 11:52:32 jperkin Exp $
#
# Tests for the command line option '--version', which may be expected to
# output the version number of make.  NetBSD's make does not have a version
# number, but the bmake distribution created from it has.

# As of 2021-12-23, the output is a single empty line since the '--' does not
# end the command line options.  Command line parsing then continues as if
# nothing had happened, and the '-version' is split into '-v ersion', which is
# interpreted as "print the expanded variable named 'ersion'".

.MAKEFLAGS: --version
