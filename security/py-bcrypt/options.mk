# $NetBSD: options.mk,v 1.2 2015/04/04 21:49:17 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-bcrypt
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
DEPENDS+=		${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
DEPENDS+=		${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
.endif
