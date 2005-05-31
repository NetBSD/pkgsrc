# $NetBSD: all.mk,v 1.2 2005/05/31 13:33:39 dillo Exp $
#
# This file tests legacy variables and precedence of the various
# option variables.
#

MAKECONF=		/dev/null

PKG_OPTIONS_LEGACY_VARS+=USE_F:f
PKG_OPTIONS_LEGACY_VARS+=USE_G:g
PKG_OPTIONS_LEGACY_VARS+=NO_H:-h

PKG_OPTIONS_VAR=	PKG_OPTIONS.foo
PKG_SUPPORTED_OPTIONS=	a  b  c  d  e  f  g  h
PKG_SUGGESTED_OPTIONS=	   b  c     e        h
PKG_DEFAULT_OPTIONS=	a -b     d
PKG_OPTIONS.foo=	     -c -d     f -g
USE_F=YES
USE_G=YES
NO_H=YES

.include "../../mk/bsd.options.mk"

.PHONY: test
test:
	echo ${PKG_OPTIONS:M*:Q}
