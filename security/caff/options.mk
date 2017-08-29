# $NetBSD: options.mk,v 1.2 2017/08/29 12:11:35 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.caff
PKG_OPTIONS_REQUIRED_GROUPS=	gnupg
PKG_OPTIONS_GROUP.gnupg=	gnupg1 gnupg2
PKG_SUGGESTED_OPTIONS=		gnupg2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnupg2)
DEPENDS+=		gnupg2>=2.0<2.1:../../security/gnupg2
.else
DEPENDS+=		gnupg>=1.4.2:../../security/gnupg
.endif
