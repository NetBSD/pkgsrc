# $NetBSD: Makefile,v 1.11 2026/05/25 13:05:12 adam Exp $

DISTNAME=	pika-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pika/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pika.readthedocs.io/
COMMENT=	Python AMQP Client Library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
