# $NetBSD: Makefile,v 1.2 2022/01/04 20:54:31 wiz Exp $

DISTNAME=	requestbuilder-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
