# $NetBSD: Makefile,v 1.40 2023/10/09 09:39:29 adam Exp $

DISTNAME=	vigra-1.11.2-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ukoethe/}
GITHUB_TAG=	Version-${PKGVERSION_NOREV:S/./-/g}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ukoethe.github.io/vigra/
COMMENT=	Computer vision library
LICENSE=	mit

EXTRACT_USING=	bsdtar
WRKSRC=		${WRKDIR}/vigra-${GITHUB_TAG}

TOOL_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

CMAKE_CONFIGURE_ARGS+=	-DDOCINSTALL:PATH=${PREFIX}/share/doc
CMAKE_CONFIGURE_ARGS+=	-DWITH_OPENEXR=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_VIGRANUMPY=OFF

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python+=	config/vigra-config.in
# Best we can do without pulling in a python dependency.
# Update when PYTHON_VERSION_DEFAULT changes!
SUBST_SED.python+=	-e 's,/usr/bin/env.*python,${PREFIX}/bin/python2.7,'
SUBST_MESSAGE.python=	Fixing path to python.

# Package doesn't need dependency, only packages using the script,
# usually during configure, so don't depend on python.
CHECK_INTERPRETER_SKIP+=	bin/vigra-config

# Don't have permissions for that anyway
CHECK_PORTABILITY_SKIP+=	config/update-gh-pages.sh.in

pre-install:
	${RM} -f ${WRKSRC}/include/vigra/*.orig

.include "../../devel/cmake/build.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
