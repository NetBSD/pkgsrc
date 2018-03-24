# $NetBSD: Makefile,v 1.21 2018/03/24 07:50:20 adam Exp $

DISTNAME=	pip-9.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pip-installer.org/
COMMENT=	Installs Python packages as an easy_install replacement
LICENSE=	mit

#TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
#TEST_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
#TEST_DEPENDS+=	${PYPKGPREFIX}-virtualenv>=1.10:../../devel/py-virtualenv

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	pip/__init__.py pip/_vendor/requests/certs.py
REPLACE_PYTHON+=	pip/_vendor/requests/packages/chardet/chardetect.py

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/pip
	${RM} -f ${DESTDIR}${PREFIX}/bin/pip[2-3]

# no tests included
do-test:
	${DO_NADA}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
