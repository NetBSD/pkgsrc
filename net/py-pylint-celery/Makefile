# $NetBSD: Makefile,v 1.1 2017/12/21 10:24:12 adam Exp $

DISTNAME=	pylint-celery-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylint-celery/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/landscapeio/pylint-celery
COMMENT=	Pylint plugin to aid Pylint in recognising the Celery library
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-astroid>=1.0:../../devel/py-astroid
DEPENDS+=	${PYPKGPREFIX}-pylint>=1.0:../../devel/py-pylint
DEPENDS+=	${PYPKGPREFIX}-pylint-plugin-utils>=0.2.1:../../devel/py-pylint-plugin-utils

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
