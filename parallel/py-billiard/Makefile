# $NetBSD: Makefile,v 1.18 2019/04/05 13:03:11 adam Exp $

DISTNAME=	billiard-3.6.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/billiard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/celery/billiard
COMMENT=	Python multiprocessing fork with improvements and bugfixes
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-case>=1.3.1:../../devel/py-case
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0:../../devel/py-test

.include "../../lang/python/pyversion.mk"
# builds _billiard.so
.if ${_PYTHON_VERSION} == 27
USE_LANGUAGES=		c
.else
USE_LANGUAGES=		# none
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
