# $NetBSD: Makefile,v 1.12 2026/08/03 09:47:31 adam Exp $

DISTNAME=	rarfile-4.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rarfile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/markokr/rarfile
COMMENT=	RAR archive reader for Python
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	unrar-[0-9]*:../../archivers/unrar

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
