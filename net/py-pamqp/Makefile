# $NetBSD: Makefile,v 1.2 2020/09/14 19:36:16 adam Exp $

DISTNAME=	pamqp-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pamqp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pamqp.readthedocs.io/
COMMENT=	RabbitMQ Focused AMQP low-level library
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
