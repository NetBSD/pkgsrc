# $NetBSD: Makefile,v 1.1 2017/09/29 21:12:20 joerg Exp $

DISTNAME=	crayons-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/crayons/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kennethreitz/crayons
COMMENT=	Colored string formatting for the terminal
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-colorama-[0-9]*:../../comms/py-colorama

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
