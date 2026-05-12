# $NetBSD: Makefile,v 1.7 2026/05/12 08:13:33 adam Exp $

DISTNAME=	pamqp-4.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pamqp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pamqp.readthedocs.io/
COMMENT=	RabbitMQ Focused AMQP low-level library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
