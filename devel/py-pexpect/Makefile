# $NetBSD: Makefile,v 1.24 2018/05/30 07:58:48 adam Exp $

DISTNAME=	pexpect-4.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pexpect/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://pexpect.readthedocs.io/
COMMENT=	Pure Python Expect-like module
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-ptyprocess>=0.5:../../sysutils/py-ptyprocess

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
