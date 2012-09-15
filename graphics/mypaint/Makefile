# $NetBSD: Makefile,v 1.13 2012/09/15 10:05:04 obache Exp $
#

DISTNAME=	mypaint-1.0.0
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://download.gna.org/mypaint/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://mypaint.intilinux.com/
COMMENT=	Fast and easy open-source graphics application for digital painters
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++

USE_TOOLS+=	bash:run msgfmt pkg-config

BUILD_DEPENDS+=	scons-[0-9]*:../../devel/scons
DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2
DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo

FIND_PREFIX:=	SCONSDIR=scons
.include "../../mk/find-prefix.mk"

SUBST_CLASSES+=			locale-dir
SUBST_STAGE.locale-dir=		pre-configure
SUBST_FILES.locale-dir=		SConstruct
SUBST_SED.locale-dir=		-e 's,share/locale,${PKGLOCALEDIR}/locale,'
USE_PKGLOCALEDIR=	yes

SUBST_CLASSES+=			python
SUBST_STAGE.python=		pre-configure
SUBST_FILES.python=		brushlib/generate.py \
				SConstruct
SUBST_SED.python=		-e 's,/usr/bin/env python,${PYTHONBIN},'
SUBST_SED.python+=		-e 's,%PYTHONBIN%,${PYTHONBIN},'

REPLACE_BASH=			brushes/label-brush-mypaint.sh

do-build:
	cd ${WRKSRC} && cd ${BUILD_DIRS} && \
		${SETENV} ${MAKE_ENV} \
		${SCONSDIR}/bin/scons prefix=${PREFIX}

do-install:
	cd ${WRKSRC} && cd ${INSTALL_DIRS} && \
		${SETENV} ${MAKE_ENV} \
		${SCONSDIR}/bin/scons prefix=${DESTDIR}${PREFIX} install

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
