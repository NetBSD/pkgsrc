# $NetBSD: Makefile,v 1.16 2017/07/30 22:32:20 wiz Exp $

DISTNAME=	billiard-3.5.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_PYPI:=b/billiard/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/celery/billiard
COMMENT=	Python multiprocessing fork with improvements and bugfixes
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-case>=1.3.1:../../devel/py-case
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=3.0:../../devel/py-test

.include "../../lang/python/pyversion.mk"
# builds _billiard.so
.if "${PYPKGPREFIX}" == "py27"
USE_LANGUAGES=		c
.else
USE_LANGUAGES=		# empty
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
