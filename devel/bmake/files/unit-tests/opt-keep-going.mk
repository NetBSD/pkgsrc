# $NetBSD: opt-keep-going.mk,v 1.2 2024/09/17 11:52:32 jperkin Exp $
#
# Tests for the -k command line option, which stops building a target as soon
# as an error is detected, but continues building the other, independent
# targets, as far as possible.
#
# Until 2020-12-07, if a dependency of the main target failed, the exit
# status was nevertheless 0, which was wrong since the main targets could
# not be made.  This was only wrong in -k mode combined with compat mode.

.MAKEFLAGS: -d0			# switch stdout to being line-buffered
.MAKEFLAGS: -k

all: dependency other

dependency:
	@echo dependency 1
	@false
	@echo dependency 2
	@:; exit 7
	@echo dependency 3

other:
	@echo other 1
	@false
	@echo other 2

all:
	@echo main 1
	@false
	@echo main 2
