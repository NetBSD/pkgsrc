# $NetBSD: Makefile,v 1.22 2017/09/03 08:53:05 wiz Exp $

DISTNAME=	chardet-3.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/chardet/}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/chardet
COMMENT=	Character encoding auto-detection in Python
LICENSE=	gnu-lgpl-v2.1

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
BUILD_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
BUILD_DEPENDS+=	${PYPKGPREFIX}-py-[0-9]*:../../devel/py-py

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/chardetect ${DESTDIR}${PREFIX}/bin/chardetect-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
