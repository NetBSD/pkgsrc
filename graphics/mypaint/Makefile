# $NetBSD: Makefile,v 1.34 2018/11/12 03:52:15 ryoon Exp $

DISTNAME=	mypaint-1.2.1
PKGREVISION=	1
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

BUILD_DEPENDS+=	scons-[0-9]*:../../devel/scons
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

USE_LANGUAGES=	c c++

USE_TOOLS+=	bash:run msgfmt pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2

USE_PKGLOCALEDIR=	yes

SUBST_CLASSES+=			python
SUBST_STAGE.python=		pre-configure
SUBST_FILES.python=		SConscript
SUBST_VARS.python=		PYTHONBIN

LDFLAGS+=	-lintl

REPLACE_BASH=			brushes/label-brush-mypaint.sh

do-build:
	${LN} -sf ${PREFIX}/bin/swig2.0 \
		${BUILDLINK_DIR}/bin/swig
	cd ${WRKSRC} && cd ${BUILD_DIRS} && \
		${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/scons \
			prefix=${DESTDIR}${PREFIX} \
			enable_profiling=False

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
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
