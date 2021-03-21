# $NetBSD: Makefile,v 1.5 2021/03/21 20:10:15 adam Exp $

DISTNAME=	crayons-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/crayons/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kennethreitz/crayons
COMMENT=	Colored string formatting for the terminal
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-colorama-[0-9]*:../../comms/py-colorama

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
