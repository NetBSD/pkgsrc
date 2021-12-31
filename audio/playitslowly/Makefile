# $NetBSD: Makefile,v 1.13 2021/12/31 08:10:03 wiz Exp $

DISTNAME=	playitslowly-1.5.1
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	https://29a.ch/playitslowly/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://29a.ch/playitslowly/
COMMENT=	Play back audio files at a different speed or pitch
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-gstreamer1-[0-9]*:../../multimedia/py-gstreamer1
DEPENDS+=	gst-plugins1-soundtouch-[0-9]*:../../audio/gst-plugins1-soundtouch

PYTHON_VERSIONED_DEPENDENCIES+=	cairo

REPLACE_PYTHON+=	playitslowly/app.py

SUBST_CLASSES+=		exec
SUBST_SED.exec+=	-e "s,exec python,exec ${PYTHONBIN},"
SUBST_FILES.exec+=	bin/playitslowly
SUBST_STAGE.exec=	post-build
SUBST_MESSAGE.exec=	Fixing path to python interpreter.

USE_LANGUAGES=	# none

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
