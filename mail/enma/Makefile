# $NetBSD: Makefile,v 1.3 2009/12/15 16:40:01 joerg Exp $
#

DISTNAME=	enma-1.1.0
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

BUILDLINK_TRANSFORM+=	opt:-lbind:${RESOLV_LDFLAGS}

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

INSTALLATION_DIRS+=	share/examples/enma

post-install:
	${INSTALL_DATA} ${WRKSRC}/enma/etc/enma.conf.sample \
		${DESTDIR}${PREFIX}/share/examples/enma/enma.conf.sample

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.if ${OPSYS} == "DragonFly"
USE_BUILTIN.resolv=	no
.endif
.include "../../mk/resolv.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
