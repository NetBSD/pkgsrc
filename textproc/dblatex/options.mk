# $NetBSD: options.mk,v 1.2 2017/10/03 15:12:42 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dblatex
PKG_SUPPORTED_OPTIONS=	dblatex-fig
PKG_SUGGESTED_OPTIONS=	dblatex-fig

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdblatex-fig)
DEPENDS+=	fig2dev-[0-9]*:../../print/fig2dev
.endif
