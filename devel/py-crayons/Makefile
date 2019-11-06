# $NetBSD: Makefile,v 1.3 2019/11/06 17:31:40 adam Exp $

DISTNAME=	crayons-0.3.0
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
