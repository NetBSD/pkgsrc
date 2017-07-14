# $NetBSD: Makefile,v 1.14 2017/07/14 07:52:39 adam Exp $

DISTNAME=	amqp-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/amqp/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://amqp.readthedocs.io/
COMMENT=	Low-level AMQP client for Python
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-vine>=1.1.3:../../devel/py-vine
BUILD_DEPENDS+=	${PYPKGPREFIX}-case>=1.3.1:../../devel/py-case
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=3.0:../../devel/py-test

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
