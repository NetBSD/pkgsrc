# $NetBSD: Makefile,v 1.6 2022/01/04 20:52:58 wiz Exp $

DISTNAME=	crayons-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
