# $NetBSD: Makefile,v 1.10 2019/12/03 17:19:01 adam Exp $

DISTNAME=	txAMQP-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/txAMQP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/txamqp/txamqp
COMMENT=	Python library for communicating with AMQP using Twisted
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
