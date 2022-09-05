# $NetBSD: Makefile,v 1.5 2022/09/05 11:24:49 adam Exp $

DISTNAME=	pika-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pika/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pika.readthedocs.io/
COMMENT=	Python AMQP Client Library
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
