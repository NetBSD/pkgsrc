# $NetBSD: Makefile,v 1.4 2023/09/24 22:42:29 nros Exp $

DISTNAME=	lepton-1.2.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=dropbox/}
GITHUB_TAG=	911d79a560c303a2a62e5412117d0a4ccb41836d

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dropbox/lepton/
COMMENT=	Lossless compression/decompression for JPEG images
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++11
USE_TOOLS+=	autoconf autoreconf automake gmake makeinfo

AUTO_MKDIRS=	yes

CONFIGURE_ARGS+=	--enable-system-dependencies

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} sh ./autogen.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lepton ${DESTDIR}${PREFIX}/bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
