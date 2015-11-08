# $NetBSD: Makefile,v 1.4 2015/11/08 06:56:54 dholland Exp $

DISTNAME=	3.16
PKGREVISION=	2
PKGNAME=	flickrnet-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=samjudson/flickr-net/archive/}

COMMENT=	.NET library for accessing Flickr
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/flickr-net-${DISTNAME}
USE_TOOLS+=	pkg-config

SUBST_CLASSES+=			fix-prefix
SUBST_STAGE.fix-prefix=		pre-configure
SUBST_MESSAGE.fix-prefix=	Fix pkg-config prefix
SUBST_FILES.fix-prefix=		flickrnet.pc
SUBST_SED.fix-prefix=		-e 's,\@prefix\@,${PREFIX},'

do-build:
	cd ${WRKSRC} && \
	xbuild FlickrNet/FlickrNet.csproj

do-install:
	mkdir ${DESTDIR}/${PREFIX}/lib/flickrnet
	install ${WRKSRC}/FlickrNet/bin/Debug/FlickrNet.* \
		${DESTDIR}/${PREFIX}/lib/flickrnet
	mkdir ${DESTDIR}/${PREFIX}/lib/pkgconfig
	install ${WRKSRC}/flickrnet.pc \
		${DESTDIR}/${PREFIX}/lib/pkgconfig/flickrnet.pc

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
