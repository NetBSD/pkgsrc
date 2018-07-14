# $NetBSD: Makefile,v 1.2 2018/07/14 12:11:32 adam Exp $

DISTNAME=	pylint-common-0.2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylint-common/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/landscapeio/pylint-common
COMMENT=	Pylint plugin to improve error analysis of the standard Python library
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-pylint>=1.0:../../devel/py-pylint
DEPENDS+=	${PYPKGPREFIX}-pylint-plugin-utils>=0.2.5:../../devel/py-pylint-plugin-utils

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # pylint-plugin-utils

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
