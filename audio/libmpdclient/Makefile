# $NetBSD: Makefile,v 1.15 2019/12/05 22:46:49 nia Exp $

DISTNAME=	libmpdclient-2.17
CATEGORIES=	audio
MASTER_SITES=	https://www.musicpd.org/download/libmpdclient/2/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MusicPlayerDaemon/libmpdclient
COMMENT=	Asynchronous API library for interfacing MPD
LICENSE=	modified-bsd

LDFLAGS.SunOS+=	-lsocket

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
