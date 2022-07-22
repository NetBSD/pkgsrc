# $NetBSD: options.mk,v 1.1 2022/07/22 01:00:24 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-approvaltests
PKG_SUPPORTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
DEPENDS+=		${PYPKGPREFIX}-pyperclip>=1.5.27:../../x11/py-pyperclip
.endif
