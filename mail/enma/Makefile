# $NetBSD: Makefile,v 1.1.1.1 2008/09/05 07:23:44 obache Exp $
#

DISTNAME=	enma-1.0.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=enma/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://enma.sourceforge.net/
COMMENT=	Sender authentication milter supporting SPF and Sender ID

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--with-libmilter=${BUILDLINK_PREFIX.libmilter}
#CONFIGURE_ARGS+=	--with-libbind=${BUILDLINK_PREFIX.bind}
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share/examples/enma

BUILDLINK_TRANSFORM+=	rename:-lbind:${RESOLV_LDFLAGS}

BUILD_DEFS+=	VARBASE

CONF_FILES+=	share/examples/enma/enma.conf.sample ${PKG_SYSCONFDIR}/enma.conf
RCD_SCRIPTS=	enma

.include "../../mk/bsd.prefs.mk"

ENMA_USER?=	daemon
ENMA_GROUP?=	daemon

PKG_GROUPS_VARS=	ENMA_GROUP
PKG_USERS_VARS=		ENMA_USER

PKG_GROUPS=	${ENMA_GROUP}
PKG_USERS=	${ENMA_USER}:${ENMA_GROUP}

SUBST_CLASSES+=		varbase
SUBST_STAGE.varbase=	post-configure
SUBST_FILES.varbase=	enma/etc/enma.conf.sample
SUBST_FILES.varbase+=	enma/man/enma.1 enma/man/enma.ja.1
SUBST_FILES.varbase+=	enma/src/enma_config.c
SUBST_SED.varbase=	-e 's;/var/;${VARBASE}/;g'

SUBST_CLASSES+=		daemon
SUBST_STAGE.daemon=	post-configure
SUBST_FILES.daemon=	enma/etc/enma.conf.sample
SUBST_SED.daemon=	-e 's;daemon;${ENMA_USER};g'

OWN_DIRS_PERMS+=	${VARBASE}/run/enma ${ENMA_USER} ${ENMA_GROUP} 0700

INSTALLATION_DIRS+=	${PKGMANDIR}/ja_JP.EUC/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/enma/man/enma.ja.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/ja_JP.EUC/man1/enma.1

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/resolv.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
