# $NetBSD: options.mk,v 1.5 2018/01/09 10:22:47 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.p5_GnuPG_Interface
PKG_OPTIONS_REQUIRED_GROUPS=	gnupg
PKG_OPTIONS_GROUP.gnupg=	gnupg1 # gnupg2
PKG_SUGGESTED_OPTIONS=		gnupg1

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnupg2)
# patch available at
# https://github.com/bestpractical/gnupg-interface/pull/1
DEPENDS+=		gnupg2-[0-9]*:../../security/gnupg2
.else
DEPENDS+=		gnupg>=1.4.2:../../security/gnupg
.endif
