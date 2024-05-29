# $NetBSD: Makefile,v 1.107 2024/05/29 16:33:01 adam Exp $

DISTNAME=	pfstools-2.2.0
PKGREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pfstools/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pfstools.sourceforge.net/
COMMENT=	Tools for manipulating HDR images and video frames
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	dcraw-[0-9]*:../../graphics/dcraw

MAKE_JOBS_SAFE=	no # libpfs must be built first

USE_CXX_FEATURES+=	c++14
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		bash perl pkg-config
PKGCONFIG_OVERRIDE+=	src/pfs/pfs.pc.in
CMAKE_ARGS+=		-DBASH_EXECUTABLE=${TOOLS_BASH}
CMAKE_ARGS+=		-DPKGMANDIR=${PKGMANDIR}
CMAKE_ARGS+=		-DWITH_MATLAB=OFF
CMAKE_ARGS+=		-DWITH_OpenCV=OFF
#CXXFLAGS+=		-std=c++14  # OpenEXR

REPLACE_BASH+=		src/camera/pfs_automerge
REPLACE_PYTHON+=	src/camera/pfs_split_exposures.py

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing paths in CMake modules.
SUBST_FILES.paths=	cmake/Find*.cmake
SUBST_SED.paths=	-e 's,/usr/local,${PREFIX},g'

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	pre-configure
SUBST_MESSAGE.perl=	Imprinting Perl path.
SUBST_FILES.perl=	src/camera/pfsinhdrgen.in
SUBST_SED.perl=		-e 's,@PERL_PATH@,${PERL5},g'

.include "options.mk"

post-extract:
	${RM} ${WRKSRC}/cmake/FindOpenEXR.cmake

.include "../../devel/cmake/build.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
