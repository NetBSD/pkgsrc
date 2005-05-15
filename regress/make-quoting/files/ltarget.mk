# $NetBSD: ltarget.mk,v 1.1.1.1 2005/05/15 21:10:16 rillig Exp $
#
# This file demonstrates that the ${.TARGET} variable must be quoted when
# the target is specified directly.
#
# See also vtarget.
#

all: foo`date`

.PHONY: foo`date`
foo`date`:
	echo ${.TARGET:Q}
