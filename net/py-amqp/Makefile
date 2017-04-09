# $NetBSD: Makefile,v 1.12 2017/04/09 17:07:09 adam Exp $

DISTNAME=	amqp-2.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=a/amqp/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://amqp.readthedocs.io/
COMMENT=	Low-level AMQP client for Python
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-vine-[0-9]*:../../devel/py-vine

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
