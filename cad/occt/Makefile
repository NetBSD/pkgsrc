# $NetBSD: Makefile,v 1.7 2025/08/14 12:15:47 gdt Exp $

# \todo Update to 7.9.1.
VERSION=	7.8.0
DISTNAME=	opencascade-${VERSION}
PKGNAME=	${DISTNAME:S/opencascade/occt/}
CATEGORIES=	cad
# \todo Downloads are now via github.
MASTER_SITES=	https://distfiles.macports.org/opencascade/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dev.opencascade.org/
COMMENT=	Boundary Representation modeling toolkit and 3D geometry library
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run
WRKSRC=		${WRKDIR}/occt-V${VERSION:S/./_/g}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

CMAKE_CONFIGURE_ARGS+=	-DUSE_FREETYPE=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_EIGEN=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_RAPIDJSON=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_DOC_Overview=OFF

REPLACE_BASH+=	adm/templates/draw.sh

CXXFLAGS.SunOS+=		-DSOLARIS=1
LDFLAGS.SunOS+=			-lnsl
BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl

.include "../../mk/compiler.mk"

.if !empty(LP64PLATFORMS:@.PLAT.@${MACHINE_PLATFORM:M${.PLAT.}}@) || \
	(defined(ABI) && ${ABI} == "64")
.  if !empty(PKGSRC_COMPILER:Mclang)
OCCT_CUSTOM_COMPILER_DRIVER=	custom_clang_64.sh
.  else
OCCT_CUSTOM_COMPILER_DRIVER=	custom_gcc_64.sh
.  endif
.else
.  if !empty(PKGSRC_COMPILER:Mclang)
OCCT_CUSTOM_COMPILER_DRIVER=	custom_clang_32.sh
.  else
OCCT_CUSTOM_COMPILER_DRIVER=	custom_gcc_32.sh
.  endif
.endif

PLIST_SUBST=	OCCT_CUSTOM_COMPILER_DRIVER=${OCCT_CUSTOM_COMPILER_DRIVER:Q}
PLIST_SUBST+=	MINOR_VERSION=${VERSION:C/.[0-9]$//}

.include "../../devel/cmake/build.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../textproc/rapidjson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
