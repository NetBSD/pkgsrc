# $NetBSD: options.mk,v 1.9 2026/01/29 10:03:12 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.p5_GnuPG_Interface
PKG_OPTIONS_REQUIRED_GROUPS=	gnupg
PKG_OPTIONS_GROUP.gnupg=	gnupg1 gnupg2
PKG_SUGGESTED_OPTIONS=		gnupg2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnupg2)
DEPENDS+=		gnupg2>=2.4.9nb2:../../security/gnupg2
.endif

.if !empty(PKG_OPTIONS:Mgnupg1)
DEPENDS+=		gnupg>=1.4.23nb28:../../security/gnupg

SUBST_CLASSES+=		gpg
SUBST_SED.gpg+=		-e "s,'gpg','gpg1',g"
SUBST_FILES.gpg+=	lib/GnuPG/Interface.pm
SUBST_STAGE.gpg=	pre-configure
SUBST_MESSAGE.gpg=	Fixing path to gnupg binary.

SUBST_CLASSES+=		gpg2
SUBST_SED.gpg2+=	-e "s,gpg,gpg1,g"
SUBST_FILES.gpg2+=	Makefile.PL
SUBST_STAGE.gpg2=	pre-configure
SUBST_MESSAGE.gpg2=	Fixing path to gnupg binary.
.endif
