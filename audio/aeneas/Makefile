# $NetBSD: Makefile,v 1.35 2026/09/02 19:00:43 wiz Exp $

DISTNAME=	aeneas-1.7.3
PKGREVISION=	24
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=readbeyond/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/readbeyond/aeneas/
COMMENT=	Automagically synchronize audio and text
LICENSE=	gnu-agpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	ffmpeg6-[0-9]*:../../multimedia/ffmpeg6

USE_LANGUAGES=	c c++

MAKE_ENV+=	AENEAS_FORCE_CEW=True
WHEEL_NAME=	${DISTNAME}.0

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

# as of 1.7.3
# 100 failed, 724 passed, 105 warnings

.include "../../lang/python/wheel.mk"
.include "../../audio/espeak-ng/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
