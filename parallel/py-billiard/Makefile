# $NetBSD: Makefile,v 1.14 2017/04/09 16:43:03 adam Exp $

DISTNAME=	billiard-3.5.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_PYPI:=b/billiard/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/celery/billiard
COMMENT=	Python multiprocessing fork with improvements and bugfixes
LICENSE=	modified-bsd

.include "../../lang/python/pyversion.mk"
# builds _billiard.so
.if "${PYPKGPREFIX}" == "py27"
USE_LANGUAGES=		c
.else
USE_LANGUAGES=		# empty
.endif

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
