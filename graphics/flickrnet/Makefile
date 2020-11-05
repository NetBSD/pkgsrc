# $NetBSD: Makefile,v 1.18 2020/11/05 09:08:20 ryoon Exp $

DISTNAME=	FlickrNet-3.24.0
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=samjudson/}
GITHUB_PROJECT=	flickr-net
GITHUB_TAG=	${PKGVERSION_NOREV:S/.0//}

COMMENT=	.NET library for accessing Flickr
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/flickr-net-${PKGVERSION_NOREV:S/.0//}
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
