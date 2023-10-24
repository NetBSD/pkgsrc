# $NetBSD: Makefile,v 1.3 2023/10/24 22:08:17 wiz Exp $

DISTNAME=	ympd-1.3.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=notandy/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ympd.org/
COMMENT=	Music Player Daemon web UI
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

BUILD_DEFS+=	VARBASE

CFLAGS.SunOS+=	-D_POSIX_C_SOURCE=200112L
LDFLAGS.SunOS+=	-lnsl -lsocket

.include "../../mk/bsd.prefs.mk"

RCD_SCRIPTS+=	ympd

.if ${INIT_SYSTEM} == "rc.d"
DEPENDS+=	daemonize-[0-9]*:../../sysutils/daemonize
.endif

YMPD_USER?=		ympd
YMPD_GROUP?=		ympd
PKG_GROUPS=		${YMPD_GROUP}
PKG_USERS=		${YMPD_USER}:${YMPD_GROUP}
PKG_GROUPS_VARS=	YMPD_USER
PKG_USERS_VARS=		YMPD_GROUP

FILES_SUBST+=		YMPD_USER=${YMPD_USER}

OWN_DIRS+=		${VARBASE}/log/ympd

.include "options.mk"
.include "../../audio/libmpdclient/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
