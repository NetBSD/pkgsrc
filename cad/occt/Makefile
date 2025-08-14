# $NetBSD: Makefile,v 1.8 2025/08/14 12:48:16 gdt Exp $

VERSION=	7.8.0
DISTNAME=	opencascade-${VERSION}
PKGNAME=	${DISTNAME:S/opencascade/occt/}
CATEGORIES=	cad
MASTER_SITES=	https://distfiles.macports.org/opencascade/
EXTRACT_SUFX=	.tgz
WRKSRC=		${WRKDIR}/occt-V${VERSION:S/./_/g}

# VERSION=	7.9.1
# VERSION_GH=	7_9_1
# # Name the distfile to match the unpack directory.
# DISTNAME=	OCCT-${VERSION_GH}
# PKGNAME=	occt-${VERSION}
# CATEGORIES=	cad
# MASTER_SITES=	${MASTER_SITE_GITHUB:=Open-Cascade-SAS/}
# GITHUB_PROJECT=	OCCT
# GITHUB_TAG=	refs/tags/V${VERSION_GH}
# DIST_SUBDIR=	occt
# WRKSRC=		${WRKDIR}/${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dev.opencascade.org/
COMMENT=	Boundary Representation modeling toolkit and 3D geometry library
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run

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
