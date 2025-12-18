# $NetBSD: Makefile,v 1.21 2025/12/18 13:40:09 nia Exp $

DISTNAME=	libmpdclient-2.20
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://www.musicpd.org/download/libmpdclient/2/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MusicPlayerDaemon/libmpdclient
COMMENT=	Asynchronous API library for interfacing MPD
LICENSE=	modified-bsd

LDFLAGS.SunOS+=	-lsocket

PYTHON_FOR_BUILD_ONLY=	tool

FORCE_C_STD=	gnu99

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
