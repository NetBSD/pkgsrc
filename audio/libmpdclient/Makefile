# $NetBSD: Makefile,v 1.19 2022/04/24 13:49:07 nia Exp $

DISTNAME=	libmpdclient-2.20
CATEGORIES=	audio
MASTER_SITES=	https://www.musicpd.org/download/libmpdclient/2/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MusicPlayerDaemon/libmpdclient
COMMENT=	Asynchronous API library for interfacing MPD
LICENSE=	modified-bsd

LDFLAGS.SunOS+=	-lsocket

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
