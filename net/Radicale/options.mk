# $NetBSD: options.mk,v 1.1 2015/01/28 07:22:51 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.Radicale
PKG_SUPPORTED_OPTIONS=	git

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgit)
DEPENDS+=	${PYPKGPREFIX}-dulwich-[0-9]*:../../devel/py-dulwich
.endif
