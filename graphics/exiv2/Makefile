# $NetBSD: Makefile,v 1.51 2023/01/24 18:36:26 wiz Exp $

DISTNAME=	exiv2-0.27.5-Source
PKGNAME=	${DISTNAME:S/-Source//}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=Exiv2/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.exiv2.org/
COMMENT=	Image metadata manipulation
LICENSE=	gnu-gpl-v2

CHECK_PORTABILITY_SKIP+=	contrib/coverity.sh

USE_TOOLS+=	msgfmt
USE_LANGUAGES=	c c++
GCC_REQD+=	3.3

.include "../../mk/bsd.prefs.mk"

CMAKE_ARGS+=	-DEXIV2_BUILD_SAMPLES:BOOL=OFF
# turn on BMFF support -- will be default as of 1.00
CMAKE_ARGS+=	-DEXIV2_ENABLE_BMFF:BOOL=ON
.if ${OPSYS} == "Darwin"
CMAKE_ARGS+=	-DIntl_INCLUDE_DIR=${BUILDLINK_PREFIX.gettext}/include
.endif

LDFLAGS.Linux+=	-ldl
LDFLAGS.SunOS+=	-lsocket -lnsl

CXXFLAGS.SunOS+=	-fPIC

PKGCONFIG_OVERRIDE=	cmake/exiv2.pc.in

.include "../../devel/cmake/build.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
