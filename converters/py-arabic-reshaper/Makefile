# $NetBSD: Makefile,v 1.4 2022/01/05 09:37:15 wiz Exp $

DISTNAME=	arabic_reshaper-2.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	3
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/arabic-reshaper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mpcabd/python-arabic-reshaper
COMMENT=	Reconstruct Arabic sentences
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-configparser-[0-9]*:../../devel/py-configparser
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
