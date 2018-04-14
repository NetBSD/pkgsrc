# $NetBSD: Makefile,v 1.1 2018/04/14 13:54:46 adam Exp $

DISTNAME=	requestbuilder-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requestbuilder/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/boto/requestbuilder
COMMENT=	Command line-driven HTTP request builder
LICENSE=	isc

DEPENDS+=	${PYPKGPREFIX}-requests>=2.4:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
