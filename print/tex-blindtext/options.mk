# $NetBSD: options.mk,v 1.1 2017/01/20 21:43:58 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tex-blindtext
BLINDTEXT_LANGUAGES=	catalan english french german latin
PKG_SUPPORTED_OPTIONS+=	$(BLINDTEXT_LANGUAGES) polyglossia
PKG_SUGGESTED_OPTIONS+=	english

.include "../../mk/bsd.options.mk"

.for l in $(BLINDTEXT_LANGUAGES)
.if !empty(PKG_OPTIONS:M$(l))
DEPENDS+=	tex-babel-$(l)-[0-9]*:../../print/tex-babel-$(l)
.endif
.endfor

.if !empty(PKG_OPTIONS:Mpolyglossia)
DEPENDS+=	tex-polyglossia-[0-9]*:../../print/tex-polyglossia
.endif
