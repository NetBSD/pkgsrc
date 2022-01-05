# $NetBSD: Makefile,v 1.29 2022/01/05 15:40:59 wiz Exp $

DISTNAME=	chardet-4.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/chardet/}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/chardet
COMMENT=	Character encoding auto-detection in Python
LICENSE=	gnu-lgpl-v2.1

TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-py-[0-9]*:../../devel/py-py

PYTHON_VERSIONED_DEPENDENCIES=	hypothesis:test

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} chardetect chardetect-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
