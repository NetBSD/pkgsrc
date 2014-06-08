# $NetBSD: Makefile,v 1.1 2014/06/08 23:09:53 rodent Exp $

DISTNAME=	softlayer_messaging-1.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	https://pypi.python.org/packages/source/s/softlayer_messaging/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://sldn.softlayer.com/reference/messagequeueapi
COMMENT=	SoftLayer Message Queue client
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
