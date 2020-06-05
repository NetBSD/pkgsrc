# $NetBSD: Makefile,v 1.2 2020/06/05 12:49:07 jperkin Exp $

DISTNAME=	jbig2enc-0.29pre
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=agl/}
GITHUB_TAG=	0693dcd027f333d8499a4717b6452de08b6834ed

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/agl/jbig2enc
COMMENT=	JBIG2 encoder
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf autoheader automake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/leptonica/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
