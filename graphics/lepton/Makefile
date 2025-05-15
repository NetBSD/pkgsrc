# $NetBSD: Makefile,v 1.5 2025/05/15 09:04:12 nia Exp $

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
USE_LANGUAGES+=	c c++
USE_TOOLS+=	autoconf autoreconf automake gmake makeinfo

AUTO_MKDIRS=	yes

USE_CXX_FEATURES+=	c++11

# Has a hard requirement on SSE.
ONLY_FOR_PLATFORM+=	*-*-i386 *-*-x86_64

CONFIGURE_ARGS+=	--enable-system-dependencies

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} sh ./autogen.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lepton ${DESTDIR}${PREFIX}/bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
