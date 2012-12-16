# $NetBSD: Makefile,v 1.1 2012/12/16 16:10:56 ryoon Exp $
#

DISTNAME=	mandelbulber1.13-1
PKGNAME=	${DISTNAME:S/-/./:S/mandelbulber/mandelbulber-/}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mandelbulber/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.mandelbulber.com/
COMMENT=	3D fractal explorer
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake pax pkg-config
USE_LANGUAGES=	c++

BUILD_DIRS=	makefiles
MAKE_FILE=	makefile

SUBST_CLASSES+=		lib
SUBST_STAGE.lib=	pre-configure
SUBST_MESSAGE.lib=	Fix library path, CXXFLAGS, and CXX.
SUBST_FILES.lib+=	makefiles/makefile
SUBST_FILES.lib+=	makefiles/src/subdir.mk
SUBST_SED.lib+=		-e 's;g++;${CXX:Q} ${CXXFLAGSQ} ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gtk2}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.freetype2}/lib;'
SUBST_SED.lib+=		-e 's,/usr/lib/x86_64-linux-gnu/,${PREFIX}/lib,'

CXXFLAGS+=	-DSHARED_DIR=\\"${PREFIX}/share/mandelbulber\\"

INSTALLATION_DIRS=	bin share/mandelbulber

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/makefiles/mandelbulber \
		${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/usr/share && pax -rw -pmp * \
		${DESTDIR}${PREFIX}/share/mandelbulber

.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
