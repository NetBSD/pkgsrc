# $NetBSD: options.mk,v 1.1.1.1 2005/01/16 21:36:28 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.imp
PKG_SUPPORTED_OPTIONS=	ispell aspell gnupg

.include "../../mk/bsd.options.mk"

###
### Use aspell with IMP
###
.if !empty(PKG_OPTIONS:Maspell)
DEPENDS+=	aspell-[0-9]*:../../textproc/aspell
.endif

###
### Use ispell with IMP
###
.if !empty(PKG_OPTIONS:Mispell)
DEPENDS+=	ispell-base-[0-9]*:../../textproc/ispell-base
.endif

###
### Use gnupg with IMP
###
.if !empty(PKG_OPTIONS:Mgnupg)
DEPENDS+=	gnupg-[0-9]*:../../security/gnupg
.endif
