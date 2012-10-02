# $NetBSD: Makefile,v 1.14 2012/10/02 23:48:01 asau Exp $

DISTNAME=	mt-daapd-0.2.4.2
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mt-daapd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mt-daapd.org/
COMMENT=	Server for DAAP (iTunes)

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

CPPFLAGS.SunOS+=	-std=c99 -Du_int32_t=uint32_t

RCD_SCRIPTS=	mtdaapd
EGDIR=		${PREFIX}/share/examples/${PKGBASE}
MTDAAPD_USER?=	mtdaapd
MTDAAPD_GROUP?=	mtdaapd
PKG_USERS=	${MTDAAPD_USER}:${MTDAAPD_GROUP}
PKG_GROUPS=	${MTDAAPD_GROUP}
BUILD_DEFS+=	VARBASE

PKG_USERS_VARS+=	MTDAAPD_USER
PKG_GROUPS_VARS+=	MTDAAPD_GROUP

CONF_FILES_PERMS=	${EGDIR}/mt-daapd.conf ${PKG_SYSCONFDIR}/mt-daapd.conf \
			${MTDAAPD_USER} ${MTDAAPD_GROUP} 0660

OWN_DIRS_PERMS=		${VARBASE}/cache/mt-daapd \
			${MTDAAPD_USER} ${MTDAAPD_GROUP} 0750

.include "options.mk"

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	contrib/mt-daapd.conf
SUBST_SED.conf=		-e "s,@PREFIX@,${PREFIX},"
SUBST_SED.conf+=	-e "s,@VARBASE@,${VARBASE},g"
SUBST_SED.conf+=	-e "s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},"
SUBST_SED.conf+=	-e "s,@MTDAAPD_USER@,${MTDAAPD_USER},"

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	src/main.c
SUBST_SED.paths=	-e "s,/etc,${PKG_SYSCONFDIR},"
SUBST_SED.paths+=	-e "s,/var,${VARBASE},"

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/contrib/mt-daapd.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/mt-daapd.playlist ${DESTDIR}${EGDIR}

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
