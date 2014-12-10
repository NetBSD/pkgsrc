# $NetBSD: options.mk,v 1.1 2014/12/10 12:27:27 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dblatex
PKG_SUPPORTED_OPTIONS=	dblatex-fig
PKG_SUGGESTED_OPTIONS=	dblatex-fig

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdblatex-fig)
DEPENDS+=	transfig-[0-9]*:../../print/transfig
.endif
