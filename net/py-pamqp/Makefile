# $NetBSD: Makefile,v 1.8 2026/07/08 09:12:15 adam Exp $

DISTNAME=	pamqp-4.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pamqp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gmr/pamqp
COMMENT=	RabbitMQ Focused AMQP low-level library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
