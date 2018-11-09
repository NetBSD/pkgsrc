# $NetBSD: Makefile,v 1.1 2018/11/09 06:46:03 rillig Exp $

all install:
	@set -eu; \
	env | sed -n -e '/^.*_set=yes$$/p' | LC_ALL=C sort \
	> "$$REGRESS_TMPDIR/make-${.TARGET}.vars"
