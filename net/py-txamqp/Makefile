# $NetBSD: Makefile,v 1.7 2019/04/26 13:14:10 maya Exp $

DISTNAME=	python-txamqp_0.3.orig
PKGNAME=	${PYPKGPREFIX}-txamqp-0.3
CATEGORIES=	net
MASTER_SITES=	http://launchpadlibrarian.net/30388120/

MAINTAINER=	pkgsrc@NetBSD.org
HOMEPAGE=	https://launchpad.net/txamqp/
COMMENT=	Python library for communicating with AMQP using Twisted
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # as of 0.3

USE_LANGUAGES=	# none

WRKSRC=		${WRKDIR}/python-txamqp-0.3
EGG_NAME=	txAMQP-${PKGVERSION_NOREV}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
