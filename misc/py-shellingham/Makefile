# $NetBSD: Makefile,v 1.4 2023/08/24 20:26:50 wiz Exp $

DISTNAME=	shellingham-1.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/post//}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/shellingham/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sarugaku/shellingham
COMMENT=	Tool to detect surrounding shell
LICENSE=	isc

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# needs 'make install'
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
