# $NetBSD: Makefile,v 1.10 2022/08/24 09:25:56 wiz Exp $

DISTNAME=	kazoo-2.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kazoo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kazoo.readthedocs.org/
COMMENT=	Higher level Zookeeper client
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES+=	coverage:test flake8:test

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
