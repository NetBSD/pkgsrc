# $NetBSD: options.mk,v 1.6 2020/06/08 14:18:15 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.p5_GnuPG_Interface
PKG_OPTIONS_REQUIRED_GROUPS=	gnupg
PKG_OPTIONS_GROUP.gnupg=	gnupg1 gnupg2
PKG_SUGGESTED_OPTIONS=		gnupg2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnupg2)
DEPENDS+=		gnupg2>=2.2:../../security/gnupg2

SUBST_CLASSES+=		gpg
SUBST_SED.gpg+=		-e "s,'gpg','gpg2',g"
SUBST_FILES.gpg+=	lib/GnuPG/Interface.pm
SUBST_FILES.gpg+=	t/Interface.t
SUBST_STAGE.gpg=	pre-configure
SUBST_MESSAGE.gpg=	Fixing path to gnupg binary.

SUBST_CLASSES+=		gpg2
SUBST_SED.gpg2+=	-e "s,gpg,gpg2,g"
SUBST_FILES.gpg2+=	Makefile.PL
SUBST_STAGE.gpg2=	pre-configure
SUBST_MESSAGE.gpg2=	Fixing path to gnupg binary.
.endif

.if !empty(PKG_OPTIONS:Mgnupg1)
DEPENDS+=		gnupg>=1.4.2:../../security/gnupg
.endif
