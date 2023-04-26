# $NetBSD: Makefile,v 1.59 2023/04/26 15:45:03 wiz Exp $

DISTNAME=	faad2-2.10.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=knik0/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/knik0/faad2
COMMENT=	AAC decoding library
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake autoreconf gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/faad2

LIBS+=			-lm
CPPFLAGS.SunOS+=	-D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE=1

post-extract:
	${MV} ${WRKSRC}/frontend/faad.man ${WRKSRC}/frontend/faad.1

pre-configure:
	cd ${WRKSRC} && autoreconf -if

.include "../../mk/bsd.pkg.mk"
