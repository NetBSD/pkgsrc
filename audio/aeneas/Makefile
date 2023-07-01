# $NetBSD: Makefile,v 1.19 2023/07/01 08:37:33 wiz Exp $

DISTNAME=	aeneas-1.7.3
PKGREVISION=	15
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=readbeyond/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/readbeyond/aeneas/
COMMENT=	Automagically synchronize audio and text
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	c c++

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

MAKE_ENV+=	AENEAS_FORCE_CEW=True
EGG_NAME=	${DISTNAME}.0

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

.include "../../lang/python/egg.mk"
.include "../../audio/espeak/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
