# $NetBSD: options.mk,v 1.3 2006/01/01 18:53:03 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.trn
PKG_OPTIONS_REQUIRED_GROUPS=	nntpclient
PKG_OPTIONS_GROUP.nntpclient=	trn-inn trn-nntpclnt
PKG_SUGGESTED_OPTIONS+=	trn-nntpclnt

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minn)
DEPENDS+=		inn>=2.2:../../news/inn
.else
DEPENDS+=		nntpclnt>=1.6.1:../../news/nntpclnt
.endif
