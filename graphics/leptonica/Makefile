# $NetBSD: Makefile,v 1.22 2022/07/14 23:46:23 dholland Exp $

DISTNAME=	leptonica-1.82.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=danbloomberg/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.leptonica.org/
COMMENT=	Software for image processing and image analysis applications
LICENSE=	2-clause-bsd

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

# The presence of fmemopen() assumes open_memstream() is also available,
# which is wrong on platforms other than Linux.
.if ${OPSYS} != "Linux"
CONFIGURE_ENV+=		ac_cv_func_fmemopen=no
.endif

# Silence console messages
CPPFLAGS+=		-DNO_CONSOLE_IO=1

# Pass a SunOS that the build relies on
CPPFLAGS.SunOS+=	-D__SOLARIS__=1

.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
