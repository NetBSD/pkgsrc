# $NetBSD: options.mk,v 1.1 2005/12/01 19:29:26 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.trn
PKG_OPTIONS_REQUIRED_GROUPS=	nntpclient
PKG_OPTIONS_GROUP.nntpclient=	trn-inn trn-nntpclnt
PKG_SUGGESTED_OPTIONS+=	trn-nntpclnt
# remove after 2005Q4
PKG_OPTIONS_LEGACY_VARS+=	USE_INN:trn-inn

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minn)
DEPENDS=		inn>=2.2:../../news/inn
.else
DEPENDS=		nntpclnt>=1.6.1:../../news/nntpclnt
.endif
