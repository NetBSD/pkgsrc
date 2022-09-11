# $NetBSD: Makefile,v 1.13 2022/09/11 18:10:03 wiz Exp $

DISTNAME=	txAMQP-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/txAMQP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/txamqp/txamqp
COMMENT=	Python library for communicating with AMQP using Twisted
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
