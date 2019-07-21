# $NetBSD: Makefile,v 1.40 2019/07/21 22:25:02 wiz Exp $

DISTNAME=	mypaint-1.2.1
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=mypaint/}
EXTRACT_SUFX=	.tar.xz
GITHUB_PROJECT=	mypaint
GITHUB_RELEASE=	v${PKGVERSION_NOREV}


MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://mypaint.org/
COMMENT=	Fast and easy open-source graphics application for digital painters
LICENSE=	gnu-gpl-v2

CONFLICTS+=	libmypaint-[0-9]*

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

USE_LANGUAGES=	c c++

USE_TOOLS+=	bash:run msgfmt pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # py-gtk2

USE_PKGLOCALEDIR=	yes

SUBST_CLASSES+=			python
SUBST_STAGE.python=		pre-configure
SUBST_FILES.python=		SConscript
SUBST_VARS.python=		PYTHONBIN

LDFLAGS+=	-lintl

REPLACE_BASH=			brushes/label-brush-mypaint.sh

SCONS_ARGS+=	enable_profiling=False
SCONS_ARGS+=	enable_openmp=False
SCONS_ARGS+=	prefix=${DESTDIR}${PREFIX}

do-build:
	${LN} -sf ${PREFIX}/bin/swig2.0 \
		${BUILDLINK_DIR}/bin/swig
	cd ${WRKSRC} && cd ${BUILD_DIRS} && \
		${SETENV} ${MAKE_ENV} \
		${SCONSBIN} ${SCONS_ARGS}

do-install:
	cd ${WRKSRC} && cd ${INSTALL_DIRS} && \
		${SETENV} ${MAKE_ENV} \
		${SCONSBIN} ${SCONS_ARGS} install

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/scons/buildlink3.mk"
.include "../../devel/swig2/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
