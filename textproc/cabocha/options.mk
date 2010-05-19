# $NetBSD: options.mk,v 1.1.1.1 2010/05/19 12:16:25 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.cabocha
PKG_OPTIONS_NONEMPTY_SETS=	ma
PKG_OPTIONS_SET.ma=	chasen mecab
PKG_SUGGESTED_OPTIONS=	chasen

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mchasen)
CONFIGURE_ARGS+=	--with-morphological-analyzer=chasen
.include "../../textproc/chasen/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmecab)
CONFIGURE_ARGS+=	--with-morphological-analyzer=mecab
.include "../../textproc/mecab/buildlink3.mk"
.endif
