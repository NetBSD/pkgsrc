# $NetBSD: Makefile,v 1.13 2018/12/01 11:33:08 wiz Exp $

DISTNAME=	libmpdclient-2.16
CATEGORIES=	audio
MASTER_SITES=	http://www.musicpd.org/download/libmpdclient/2/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mpd.wikia.com/wiki/ClientLib:libmpdclient
COMMENT=	Asynchronous API library for interfacing MPD
LICENSE=	modified-bsd

LDFLAGS.SunOS+=	-lsocket

.include "../../devel/py-meson/build.mk"
.include "../../mk/bsd.pkg.mk"
