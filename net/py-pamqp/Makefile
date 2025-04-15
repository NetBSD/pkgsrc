# $NetBSD: Makefile,v 1.6 2025/04/15 09:51:03 adam Exp $

DISTNAME=	pamqp-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pamqp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pamqp.readthedocs.io/
COMMENT=	RabbitMQ Focused AMQP low-level library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
