# $NetBSD: options.mk,v 1.4 2017/08/29 12:23:24 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.p5_GnuPG_Interface
PKG_OPTIONS_REQUIRED_GROUPS=	gnupg
PKG_OPTIONS_GROUP.gnupg=	gnupg1 # gnupg2
PKG_SUGGESTED_OPTIONS=		gnupg1

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnupg2)
DEPENDS+=		gnupg2-[0-9]*:../../security/gnupg2
.else
DEPENDS+=		gnupg>=1.4.2:../../security/gnupg
.endif
