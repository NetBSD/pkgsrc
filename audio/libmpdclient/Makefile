# $NetBSD: Makefile,v 1.12 2018/09/28 20:49:26 wiedi Exp $

DISTNAME=	libmpdclient-2.14
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
