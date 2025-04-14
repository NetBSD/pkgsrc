# $NetBSD: Makefile,v 1.20 2025/04/14 06:04:53 adam Exp $

DISTNAME=	playitslowly-1.5.1
PKGREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	https://29a.ch/playitslowly/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://29a.ch/playitslowly/
COMMENT=	Play back audio files at a different speed or pitch
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo
DEPENDS+=	${PYPKGPREFIX}-gstreamer1-[0-9]*:../../multimedia/py-gstreamer1
DEPENDS+=	gst-plugins1-soundtouch-[0-9]*:../../audio/gst-plugins1-soundtouch

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
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
