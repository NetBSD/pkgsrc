# $NetBSD: Makefile,v 1.2 2021/07/03 21:02:54 wiz Exp $

DISTNAME=	spake2-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spake2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/warner/python-spake2
COMMENT=	Pure-Python SPAKE2
LICENSE=	mit

PYTHON_VERSIONED_DEPENDENCIES=	test:test

DEPENDS+=	${PYPKGPREFIX}-hkdf-[0-9]*:../../security/py-hkdf

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
