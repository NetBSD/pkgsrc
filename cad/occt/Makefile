# $NetBSD: Makefile,v 1.2 2023/11/12 13:20:47 wiz Exp $

DISTNAME=	opencascade-7.7.0
PKGNAME=	${DISTNAME:S/opencascade/occt/}
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	https://distfiles.macports.org/opencascade/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dev.opencascade.org/release
COMMENT=	Boundary Representation modeling toolkit and 3D geometry library
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run
WRKSRC=		${WRKDIR}/occt-V7_7_0

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

CMAKE_ARGS+=	-DUSE_FREETYPE=ON
CMAKE_ARGS+=	-DUSE_EIGEN=ON
CMAKE_ARGS+=	-DUSE_RAPIDJSON=ON
CMAKE_ARGS+=	-DBUILD_DOC_Overview=OFF

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

.include "../../devel/cmake/build.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../textproc/rapidjson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
