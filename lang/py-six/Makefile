# $NetBSD: Makefile,v 1.12 2017/09/18 07:01:53 adam Exp $

DISTNAME=	six-1.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/six/}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/six/
COMMENT=	Python 2 and 3 compatibility utilities
LICENSE=	mit

# TEST_DEPENDS
# not enabled because this is a bootstrap package
#BUILD_DEPENDS+=	${PYPKGPREFIX}-py-[0-9]*:../../devel/py-py
#BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

#BOOTSTRAP_SETUPTOOLS=	yes

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
