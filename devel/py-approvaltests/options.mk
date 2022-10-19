# $NetBSD: options.mk,v 1.2 2022/10/19 11:38:12 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-approvaltests
PKG_SUPPORTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
DEPENDS+=		${PYPKGPREFIX}-pyperclip>=1.5.29:../../x11/py-pyperclip
.endif
