# $NetBSD: Makefile,v 1.17 2024/06/05 22:44:58 wiz Exp $

DISTNAME=	ecdsa-0.19.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/ecdsa/}

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://github.com/warner/python-ecdsa
COMMENT=	Easy-to-use implementation of ECDSA cryptography
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

USE_LANGUAGES=	# none

PYTHON_27_ACCEPTED=	yes

do-test:
	cd ${WRKSRC}/src && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
