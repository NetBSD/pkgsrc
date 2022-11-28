# $NetBSD: Makefile,v 1.15 2022/11/28 18:26:03 adam Exp $

DISTNAME=	pefile-2022.5.30
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pefile/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/erocarrera/pefile
COMMENT=	Python module to read and work with PE files
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-future>=0:../../devel/py-future

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
