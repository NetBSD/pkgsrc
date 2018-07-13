# $NetBSD: Makefile,v 1.2 2018/07/13 07:54:02 adam Exp $

DISTNAME=	pylint-plugin-utils-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylint-plugin-utils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/landscapeio/pylint-plugin-utils
COMMENT=	Utilities and helpers for writing Pylint plugins
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-astroid-[0-9]*:../../devel/py-astroid
DEPENDS+=	${PYPKGPREFIX}-pylint-[0-9]*:../../devel/py-pylint

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
