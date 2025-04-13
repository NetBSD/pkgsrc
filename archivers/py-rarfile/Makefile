# $NetBSD: Makefile,v 1.9 2025/04/13 08:06:23 adam Exp $

DISTNAME=	rarfile-4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rarfile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/markokr/rarfile
COMMENT=	RAR archive reader for Python
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	bsdtar-[0-9]*:../../archivers/bsdtar

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
