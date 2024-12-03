# $NetBSD: Makefile,v 1.27 2024/12/03 08:20:41 wiz Exp $

DISTNAME=	aeneas-1.7.3
PKGREVISION=	19
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=readbeyond/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/readbeyond/aeneas/
COMMENT=	Automagically synchronize audio and text
LICENSE=	gnu-agpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	ffmpeg6-[0-9]*:../../multimedia/ffmpeg6

USE_LANGUAGES=	c c++

MAKE_ENV+=	AENEAS_FORCE_CEW=True
WHEEL_NAME=	${DISTNAME}.0

# Tries to use deprecated numpy.distuils
# https://github.com/readbeyond/aeneas/issues/312
#PYTHON_VERSIONS_ACCEPTED=	310 311
# does not work either
BROKEN=		"Removes deprecated numpy.distutils"

.include "../../lang/python/wheel.mk"
.include "../../audio/espeak-ng/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
