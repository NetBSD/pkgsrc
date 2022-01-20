# $NetBSD: options.mk,v 1.1 2022/01/20 19:03:07 rhialto Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.calibre
PKG_SUPPORTED_OPTIONS=	rar

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mrar)
DEPENDS+=	${PYPKGPREFIX}-unrardll-[0-9]*:../../archivers/py-unrardll
.endif
