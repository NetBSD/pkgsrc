# $NetBSD: Makefile,v 1.12 2022/01/29 08:48:40 wiz Exp $

DISTNAME=	logan-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/logan/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dcramer/logan
COMMENT=	Toolkit for building standalone Django applications
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-django>=1.5:../../www/py-django
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=0.8.0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.1.2:../../devel/py-nose

PYTHON_VERSIONED_DEPENDENCIES+=	flake8

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
