# $NetBSD: Makefile,v 1.1 2017/12/21 10:15:48 adam Exp $

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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
