# $NetBSD: options.mk,v 1.3 2016/05/05 12:06:38 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.enigmail
PKG_OPTIONS_REQUIRED_GROUPS=	gnupg
PKG_OPTIONS_GROUP.gnupg=	gnupg2 gnupg21
PKG_SUGGESTED_OPTIONS=		gnupg2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnupg2)
DEPENDS+=			gnupg2>=2.0.7:../../security/gnupg2
.endif

.if !empty(PKG_OPTIONS:Mgnupg21)
DEPENDS+=			gnupg21-[0-9]*:../../security/gnupg21
.endif
