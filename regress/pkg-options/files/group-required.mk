# $NetBSD: group-required.mk,v 1.2 2005/06/02 20:45:18 wiz Exp $
#
# This file tests that selecting no option from a required group
# causes the package build to fail.
#

MAKECONF=		/dev/null

PKG_OPTIONS_VAR=	PKG_OPTIONS.unused
PKG_SUPPORTED_OPTIONS=	single
PKG_OPTIONS_REQUIRED_GROUPS=	req
PKG_OPTIONS_GROUP.req=	a b

.include "../../mk/bsd.options.mk"

.PHONY: test
test:
	echo ${PKG_FAIL_REASON:Q}
