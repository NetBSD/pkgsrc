# $NetBSD: Makefile,v 1.1 2015/05/23 09:01:20 kefren Exp $

DISTNAME=	3.16
PKGNAME=	flickrnet-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=samjudson/flickr-net/archive/}

COMMENT=	.NET library for accessing Flickr
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/flickr-net-${DISTNAME}
USE_TOOLS+=	pkg-config

do-build:
	cd ${WRKSRC} && \
	xbuild FlickrNet/FlickrNet.csproj

do-install:
	mkdir ${DESTDIR}/${PREFIX}/lib/flickrnet &&
	install ${WRKSRC}/FlickrNet/bin/Debug/FlickrNet.* \
		${DESTDIR}/${PREFIX}/lib/flickrnet
	mkdir ${DESTDIR}/${PREFIX}/lib/pkgconfig
	install ${WRKSRC}/flickrnet.pc \
		${DESTDIR}/${PREFIX}/lib/pkgconfig/flickrnet.pc

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
