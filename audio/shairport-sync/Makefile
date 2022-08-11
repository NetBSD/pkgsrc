# $NetBSD: Makefile,v 1.3 2022/08/11 06:41:57 wiz Exp $

DISTNAME=	shairport-sync-3.3.9
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=mikebrady/}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/mikebrady/shairport-sync
COMMENT=	AirPlay audio player with multi-room audio synchronisation capability
LICENSE=	mit # possibly others?

USE_TOOLS+=	autoconf autoreconf automake
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

GNU_CONFIGURE=	yes

BUILD_DEFS+=	VARBASE

SHAIRPORT_GROUP?=	shairport
SHAIRPORT_USER?=	shairport

.include "../../mk/bsd.prefs.mk"

PKG_GROUPS=		${SHAIRPORT_GROUP}
PKG_USERS=		${SHAIRPORT_USER}:${SHAIRPORT_GROUP}

RCD_SCRIPTS=		${PKGBASE}

FILES_SUBST+=		SHAIRPORT_USER=${SHAIRPORT_USER}
FILES_SUBST+=		SHAIRPORT_GROUP=${SHAIRPORT_GROUP}
FILES_SUBST+=		VARBASE=${VARBASE}

CONFIGURE_ARGS+=	--with-ao
CONFIGURE_ARGS+=	--with-libdaemon
CONFIGURE_ARGS+=	--with-metadata
CONFIGURE_ARGS+=	--with-pipe
CONFIGURE_ARGS+=	--with-soxr
CONFIGURE_ARGS+=	--with-stdout

CONFIGURE_ARGS+=	--without-configfiles

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS" || \
    exists(/usr/include/sys/audioio.h)
CONFIGURE_ARGS+=	--with-sun
.endif

.if ${OPSYS} != "Darwin"
CPPFLAGS+=	-DCOMPILE_FOR_LINUX_AND_FREEBSD_AND_CYGWIN_AND_OPENBSD=1
.endif

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	pre-configure
SUBST_FILES.etc+=	shairport.c
SUBST_VARS.etc+=	PKG_SYSCONFDIR
SUBST_VARS.etc+=	VARBASE

INSTALLATION_DIRS+=	share/examples/${PKGBASE}

CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/${PKGBASE}.conf \
		${PKG_SYSCONFDIR}/${PKGBASE}.conf

OWN_DIRS_PERMS+=	${VARBASE}/run/shairport-sync \
			${SHAIRPORT_USER} ${SHAIRPORT_GROUP} 0755

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

post-install:
	${INSTALL_DATA} ${WRKSRC}/scripts/shairport-sync.conf \
	    ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/${PKGBASE}.conf

.include "options.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libsoxr/buildlink3.mk"
.include "../../devel/libconfig/buildlink3.mk"
.include "../../devel/libdaemon/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
