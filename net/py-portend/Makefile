# $NetBSD: Makefile,v 1.1 2017/02/13 17:20:06 adam Exp $

DISTNAME=	portend-1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/portend/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/portend
COMMENT=	TCP port monitoring utilities
LICENSE=	mit

USE_LANGUAGES=		# none

DEPENDS+=	${PYPKGPREFIX}-tempora-[0-9]*:../../time/py-tempora

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
