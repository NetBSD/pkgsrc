# $NetBSD: Makefile,v 1.50 2025/02/05 09:11:59 adam Exp $

DISTNAME=	picard-2.13
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/picard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://picard.musicbrainz.org/
COMMENT=	Audio file tagger
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=62.4.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-JWT>=2.0:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-charset-normalizer>=3.3:../../converters/py-charset-normalizer
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.7:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-discid>=1.0:../../audio/py-discid
DEPENDS+=	${PYPKGPREFIX}-fasteners>=0.14:../../devel/py-fasteners
DEPENDS+=	${PYPKGPREFIX}-markdown>=3.2:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-mutagen>=1.37:../../audio/py-mutagen
DEPENDS+=	${PYPKGPREFIX}-qt5>=5.11:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=6.2:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa>=6.2:../../devel/py-pyobjc-framework-Cocoa
.endif

USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
