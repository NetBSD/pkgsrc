# $NetBSD: Makefile,v 1.8 2015/03/01 15:09:56 wiz Exp $

DISTNAME=	libmpdclient-2.10
CATEGORIES=	audio
MASTER_SITES=	http://www.musicpd.org/download/libmpdclient/2/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mpd.wikia.com/wiki/ClientLib:libmpdclient
COMMENT=	Asynchronous API library for interfacing MPD
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libmpdclient.pc.in

CONFIGURE_ARGS+=	--disable-documentation

.include "../../mk/bsd.pkg.mk"
