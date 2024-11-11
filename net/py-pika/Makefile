# $NetBSD: Makefile,v 1.9 2024/11/11 07:28:49 wiz Exp $

DISTNAME=	pika-1.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pika/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pika.readthedocs.io/
COMMENT=	Python AMQP Client Library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
