# $NetBSD: options.mk,v 1.1 2014/05/03 02:27:10 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-bcrypt
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
DEPENDS+=		${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
DEPENDS+=		${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
.endif
