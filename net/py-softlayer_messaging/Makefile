# $NetBSD: Makefile,v 1.4 2022/01/04 20:54:33 wiz Exp $

DISTNAME=	softlayer_messaging-1.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/softlayer_messaging/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sldn.softlayer.com/reference/messagequeueapi
COMMENT=	SoftLayer Message Queue client
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
