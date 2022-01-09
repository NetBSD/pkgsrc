# $NetBSD: Makefile,v 1.31 2022/01/09 11:58:14 wiz Exp $

DISTNAME=	pexpect-4.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pexpect/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://pexpect.readthedocs.io/
COMMENT=	Pure Python Expect-like module
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-ptyprocess>=0.5:../../sysutils/py-ptyprocess

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
