# $NetBSD: Makefile,v 1.14 2023/07/13 10:03:25 wiz Exp $

DISTNAME=	logan-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/logan/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dcramer/logan
COMMENT=	Toolkit for building standalone Django applications
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=0.8.0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.1.2:../../devel/py-nose

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
