# $NetBSD: groups.mk,v 1.2 2005/07/26 16:12:56 dillo Exp $
#
# This file tests option groups (PKG_OPTIONS_REQUIRED_GROUPS and
# PKG_OPTIONS_OPTIONAL_GROUPS).
#

MAKECONF=			/dev/null

PKG_OPTIONS_VAR=		PKG_OPTIONS.foo
PKG_SUPPORTED_OPTIONS=		single
PKG_OPTIONS_REQUIRED_GROUPS=	abc def
PKG_OPTIONS_OPTIONAL_GROUPS=	ghi
PKG_OPTIONS_GROUP.abc=		a b c
PKG_OPTIONS_GROUP.def=		d e f
PKG_OPTIONS_GROUP.ghi=		g h i

PKG_OPTIONS.foo=	a b -a
PKG_OPTIONS.foo+=	d e f
PKG_OPTIONS.foo+=	g h i -i -h

.include "../../mk/bsd.options.mk"

.PHONY: test
test:
	echo ${PKG_FAIL_REASON:M*:Q}
	echo ${PKG_OPTIONS:M*:Q}
