# $NetBSD: Makefile,v 1.2 2015/12/05 21:25:28 adam Exp $

DISTNAME=	playitslowly-1.4.0
CATEGORIES=	audio
MASTER_SITES=	http://29a.ch/playitslowly/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://29a.ch/playitslowly/
COMMENT=	Play back audio files at a different speed or pitch
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-gobject-[0-9]*:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-gstreamer0.10-[0-9]*:../../multimedia/py-gstreamer0.10
DEPENDS+=	gst-plugins0.10-soundtouch-[0-9]*:../../audio/gst-plugins0.10-soundtouch

PYTHON_VERSIONED_DEPENDENCIES=	cairo
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35
REPLACE_PYTHON+=	playitslowly/app.py

SUBST_CLASSES+=		exec
SUBST_SED.exec+=	-e "s,exec python,exec ${PYTHONBIN},"
SUBST_FILES.exec+=	bin/playitslowly
SUBST_STAGE.exec=	post-build
SUBST_MESSAGE.exec=	Fixing path to python interpreter.

USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
