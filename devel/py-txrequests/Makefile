# $NetBSD: Makefile,v 1.1 2017/09/29 14:31:50 joerg Exp $

DISTNAME=	txrequests-0.9.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_PYPI:=t/txrequests/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tardyp/txrequests
COMMENT=	Asynchronous Python HTTP Requests for Humans
LICENSE=	apache-2.0

USE_LANGUAGES=		# none

DEPENDS+=	${PYPKGPREFIX}-requests>=1.2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-twisted>=9.0.0:../../net/py-twisted

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
