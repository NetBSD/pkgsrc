# $NetBSD: Makefile,v 1.7 2025/04/24 14:14:25 wiz Exp $

DISTNAME=	jbig2enc-0.30
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=agl/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/agl/jbig2enc
COMMENT=	JBIG2 encoder
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf autoheader automake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib

REPLACE_PYTHON=		jbig2topdf.py

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/leptonica/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
