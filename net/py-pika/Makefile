# $NetBSD: Makefile,v 1.10 2025/04/15 09:51:03 adam Exp $

DISTNAME=	pika-1.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
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
