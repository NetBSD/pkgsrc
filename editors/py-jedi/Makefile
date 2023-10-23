# $NetBSD: Makefile,v 1.14 2023/10/23 06:37:44 wiz Exp $

DISTNAME=	jedi-0.19.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	editors python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jedi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/davidhalter/jedi
COMMENT=	Autocompletion tool for Python that can be used for text editors
LICENSE=	mit

EXTRACT_USING=	bsdtar

DEPENDS+=	${PYPKGPREFIX}-parso>=0.8.3:../../lang/py-parso
TEST_DEPENDS+=	${PYPKGPREFIX}-attrs-[0-9]*:../../devel/py-attrs
TEST_DEPENDS+=	${PYPKGPREFIX}-colorama-[0-9]*:../../comms/py-colorama
TEST_DEPENDS+=	${PYPKGPREFIX}-docopt-[0-9]*:../../devel/py-docopt
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
