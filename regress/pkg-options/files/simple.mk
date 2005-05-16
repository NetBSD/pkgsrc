# $NetBSD: simple.mk,v 1.1.1.1 2005/05/16 00:09:03 rillig Exp $
#
# This file test a very simple options configuration.
#

MAKECONF=		/dev/null

PKG_SUPPORTED_OPTIONS=	a b c d e
PKG_SUGGESTED_OPTIONS=	  b c   e
PKG_OPTIONS_VAR=	PKG_OPTIONS.unused

.include "../../mk/bsd.options.mk"

.PHONY: test
test:
	echo ${PKG_OPTIONS:M*:Q}
