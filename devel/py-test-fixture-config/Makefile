# $NetBSD: Makefile,v 1.3 2019/01/28 08:41:37 adam Exp $

DISTNAME=	pytest-fixture-config-1.4.0
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-fixture-config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/manahl/pytest-plugins
COMMENT=	Fixture configuration utils for py.test
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
