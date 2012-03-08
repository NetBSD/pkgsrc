# $NetBSD: Makefile,v 1.17 2012/03/08 11:44:43 wiz Exp $

DISTNAME=	vigra-1.8.0-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://hci.iwr.uni-heidelberg.de/vigra/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hci.iwr.uni-heidelberg.de/vigra/
COMMENT=	Computer vision library
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

CMAKE_ARGS+=	-D DOCINSTALL:PATH=${PREFIX}/share/doc

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python+=	config/vigra-config.in
# Best we can do without pulling in a python dependency.
# Update when PYTHON_VERSION_DEFAULT changes!
SUBST_SED.python+=	-e 's,/usr/bin/env.*python,${PREFIX}/bin/python2.7,'
SUBST_MESSAGE.python=	Fixing path to python.

# Package doesn't need dependency, only packages using the script,
# usually during configure, so don't depend on python.
CHECK_INTERPRETER_SKIP=	bin/vigra-config

.include "options.mk"

pre-install:
	${RM} -f ${WRKSRC}/include/vigra/*.orig

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
