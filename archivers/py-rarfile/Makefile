# $NetBSD: Makefile,v 1.8 2024/11/11 07:27:51 wiz Exp $

DISTNAME=	rarfile-4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rarfile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/markokr/rarfile
COMMENT=	RAR archive reader for Python
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	bsdtar-[0-9]*:../../archivers/bsdtar

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
