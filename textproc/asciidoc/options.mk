# $NetBSD: options.mk,v 1.1 2010/08/25 02:17:27 gls Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.asciidoc
PKG_SUPPORTED_OPTIONS=	pdf epub
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpdf)
DEPENDS+=	dblatex-[0-9]*:../../textproc/dblatex
.endif
.if !empty(PKG_OPTIONS:Mepub)
DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2
DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
.endif
