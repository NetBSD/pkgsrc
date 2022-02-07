# $NetBSD: Makefile,v 1.7 2022/02/07 21:02:44 adam Exp $

DISTNAME=	pylint-plugin-utils-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylint-plugin-utils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/landscapeio/pylint-plugin-utils
COMMENT=	Utilities and helpers for writing Pylint plugins
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-pylint>=1.7:../../devel/py-pylint

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
