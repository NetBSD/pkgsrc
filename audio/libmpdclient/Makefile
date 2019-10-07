# $NetBSD: Makefile,v 1.14 2019/10/07 09:28:09 prlw1 Exp $

DISTNAME=	libmpdclient-2.16
CATEGORIES=	audio
MASTER_SITES=	http://www.musicpd.org/download/libmpdclient/2/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mpd.wikia.com/wiki/ClientLib:libmpdclient
COMMENT=	Asynchronous API library for interfacing MPD
LICENSE=	modified-bsd

LDFLAGS.SunOS+=	-lsocket

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
