# $NetBSD: Makefile,v 1.2 2022/07/03 16:23:35 nia Exp $

DISTNAME=	snapcast-0.26.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=badaix/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/badaix/snapcast
COMMENT=	Multiroom client-server audio player
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

REPLACE_PYTHON+=	server/etc/plug-ins/meta_mpd.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

CONF_FILES+=	${PREFIX}/share/examples/snapcast/snapserver.conf \
		${PKG_SYSCONFDIR}/snapserver.conf

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	pre-configure
SUBST_FILES.etc+=	server/etc/snapserver.conf
SUBST_FILES.etc+=	server/server_settings.hpp
SUBST_FILES.etc+=	server/snapserver.cpp
SUBST_FILES.etc+=	server/snapserver.1
SUBST_VARS.etc+=	PKG_SYSCONFDIR
SUBST_VARS.etc+=	VARBASE

RCD_SCRIPTS+=		snapclient
RCD_SCRIPTS+=		snapserver

SNAPCLIENT_USER?=	snapclient
SNAPCLIENT_GROUP?=	snapclient

SNAPSERVER_USER?=	snapserver
SNAPSERVER_GROUP?=	snapserver

BUILD_DEFS+=		VARBASE

.include "../../mk/bsd.prefs.mk"

FILES_SUBST+=		SNAPCLIENT_USER=${SNAPCLIENT_USER}
FILES_SUBST+=		SNAPCLIENT_GROUP=${SNAPCLIENT_GROUP}
FILES_SUBST+=		VARBASE=${VARBASE}

PKG_GROUPS+=		${SNAPCLIENT_GROUP}
PKG_GROUPS+=		${SNAPSERVER_GROUP}

PKG_USERS+=		${SNAPCLIENT_USER}:${SNAPCLIENT_GROUP}
PKG_USERS+=		${SNAPSERVER_USER}:${SNAPSERVER_GROUP}

OWN_DIRS_PERMS+=	${VARBASE}/run/snapclient \
			${SNAPCLIENT_USER} ${SNAPCLIENT_GROUP} 0755

OWN_DIRS_PERMS+=	${VARBASE}/run/snapserver \
			${SNAPCLIENT_USER} ${SNAPCLIENT_GROUP} 0755

OWN_DIRS_PERMS+=	${VARBASE}/lib/snapclient \
			${SNAPSERVER_USER} ${SNAPSERVER_GROUP} 0755

OWN_DIRS_PERMS+=	${VARBASE}/lib/snapserver \
			${SNAPSERVER_USER} ${SNAPSERVER_GROUP} 0755

post-install:
	cd ${WRKSRC} && ${CHMOD} +r ${DESTDIR}${PREFIX}/share/snapserver/plug-ins/meta_mpd.py

.include "options.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libsoxr/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
