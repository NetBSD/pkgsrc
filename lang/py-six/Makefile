# $NetBSD: Makefile,v 1.13 2018/08/20 22:36:21 szptvlfn Exp $

DISTNAME=	six-1.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/six/}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/six/
COMMENT=	Python 2 and 3 compatibility utilities
LICENSE=	mit

# not enabled because this is a bootstrap package
#TEST_DEPENDS+=	${PYPKGPREFIX}-py-[0-9]*:../../devel/py-py
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

#BOOTSTRAP_SETUPTOOLS=	yes

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
