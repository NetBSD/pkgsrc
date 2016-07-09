# $NetBSD: Makefile,v 1.23 2016/07/09 13:03:50 wiz Exp $

DISTNAME=	mypaint-1.1.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://download.gna.org/mypaint/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://mypaint.intilinux.com/
COMMENT=	Fast and easy open-source graphics application for digital painters
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	scons-[0-9]*:../../devel/scons
DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2

USE_LANGUAGES=	c c++

USE_TOOLS+=	bash:run msgfmt pkg-config

PYTHON_VERSIONED_DEPENDENCIES=	cairo
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-gtk2

USE_PKGLOCALEDIR=	yes

SUBST_CLASSES+=			python
SUBST_STAGE.python=		pre-configure
SUBST_FILES.python=		SConscript
SUBST_VARS.python=		PYTHONBIN

LDFLAGS+=	-lintl

REPLACE_BASH=			brushes/label-brush-mypaint.sh

do-build:
	cd ${WRKSRC} && cd ${BUILD_DIRS} && \
		${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/scons prefix=${DESTDIR}${PREFIX}

do-install:
	cd ${WRKSRC} && cd ${INSTALL_DIRS} && \
		${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/scons prefix=${DESTDIR}${PREFIX} install

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/swig2/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
