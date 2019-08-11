# $NetBSD: Makefile,v 1.53 2019/08/11 13:21:16 wiz Exp $

DISTNAME=	pfstools-2.0.5
PKGREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pfstools/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pfstools.sourceforge.net/
COMMENT=	Tools for manipulating HDR images and video frames
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		bash perl pkg-config
CMAKE_ARGS+=		-DBASH_EXECUTABLE=${TOOLS_BASH}
CMAKE_ARGS+=		-DPKGMANDIR=${PKGMANDIR}
CMAKE_ARGS+=		-DWITH_MATLAB=NO
CMAKE_ARGS+=		-DWITH_OpenCV=NO

PKGCONFIG_OVERRIDE+=	src/pfs/pfs.pc.in

DEPENDS+=	dcraw-[0-9]*:../../graphics/dcraw

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing paths in CMake modules.
SUBST_FILES.paths=	cmake/Find*.cmake
SUBST_SED.paths=	-e 's,/usr/local,${LOCALBASE},g'

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	pre-configure
SUBST_MESSAGE.perl=	Imprinting Perl path.
SUBST_FILES.perl=	src/camera/pfsinhdrgen.in
SUBST_SED.perl=		-e 's,@PERL_PATH@,${PERL5},g'

.include "options.mk"

.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
