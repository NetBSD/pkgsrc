# $NetBSD: options.mk,v 1.3 2018/07/03 03:48:38 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.asciidoc
PKG_SUPPORTED_OPTIONS=	pdf epub highlight

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpdf)
DEPENDS+=	dblatex-[0-9]*:../../textproc/dblatex
.endif
.if !empty(PKG_OPTIONS:Mepub)
DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2
DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
.endif
.if !empty(PKG_OPTIONS:Mhighlight)
DEPENDS+=	source-highlight-[0-9]*:../../textproc/source-highlight
.endif
