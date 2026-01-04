# $NetBSD: Makefile,v 1.3 2026/01/04 14:41:28 adam Exp $

DISTNAME=	hsaudiotag3k-1.1.3.post1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hsaudiotag3k/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pythonhosted.org/hsaudiotag3k/
COMMENT=	Read metdata (tags) of mp3, mp4, wma, ogg, flac and aiff files
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
