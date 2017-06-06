# $NetBSD: options.mk,v 1.1 2017/06/06 20:37:15 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.caff
PKG_OPTIONS_REQUIRED_GROUPS=	gnupg
PKG_OPTIONS_GROUP.gnupg=	gnupg1 gnupg2 gnupg21
PKG_SUGGESTED_OPTIONS=		gnupg2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnupg21)
DEPENDS+=		gnupg21>=2.1:../../security/gnupg21
.elif !empty(PKG_OPTIONS:Mgnupg2)
DEPENDS+=		gnupg2>=2.0<2.1:../../security/gnupg2
.else
DEPENDS+=		gnupg>=1.4.2:../../security/gnupg
.endif
