# $NetBSD: Makefile,v 1.29 2023/04/30 19:40:20 wiz Exp $

DISTNAME=	wheel-0.37.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wheel/}

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	https://github.com/pypa/wheel
COMMENT=	Built-package format for Python
LICENSE=	mit

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} wheel wheel-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} > 300
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
