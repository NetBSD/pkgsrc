# $NetBSD: Makefile,v 1.2 2016/06/08 17:43:37 wiz Exp $

DISTNAME=	softlayer_messaging-1.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/softlayer_messaging/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://sldn.softlayer.com/reference/messagequeueapi
COMMENT=	SoftLayer Message Queue client
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
