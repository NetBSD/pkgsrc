# $NetBSD: deptgt-phony.mk,v 1.2 2024/09/17 11:52:31 jperkin Exp $
#
# Tests for the special target .PHONY in dependency declarations.

# TODO: Implementation

all:


# https://gnats.netbsd.org/15164 describes that .PHONY targets are still
# looked up in directories, even though .PHONY means that these targets do
# _not_ correspond to actual files.
#
# expect: Expanding "depsrc-phony-pr-15164-*-wildcard"...
# expect: Expanding "deptgt-phony-pr-15164-*-wildcard"...
.MAKEFLAGS: -dds
depsrc-phony-pr-15164: .PHONY
	: Making ${.TARGET}
depsrc-phony-pr-15164-*-wildcard: .PHONY
	: Making ${.TARGET}

.PHONY: deptgt-phony-pr-15164
deptgt-phony-pr-15164:
	: Making ${.TARGET}

.PHONY: deptgt-phony-pr-15164-*-wildcard
deptgt-phony-pr-15164-*-wildcard:
	: Making ${.TARGET}

all: depsrc-phony-pr-15164 depsrc-phony-pr-15164-*-wildcard
all: deptgt-phony-pr-15164 deptgt-phony-pr-15164-*-wildcard
