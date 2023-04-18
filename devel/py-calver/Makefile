# $NetBSD: Makefile,v 1.1 2023/04/18 17:09:39 adam Exp $

DISTNAME=	calver-2022.6.26
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/calver/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/di/calver
COMMENT=	Setuptools extension for CalVer package versions
LICENSE=	apache-2.0

#DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
