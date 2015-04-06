# $NetBSD: options.mk,v 1.3 2015/04/06 13:09:53 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-bcrypt
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
DEPENDS+=		${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
.endif
