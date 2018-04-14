# $NetBSD: Makefile,v 1.23 2018/04/14 05:20:25 adam Exp $

DISTNAME=	pexpect-4.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pexpect/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://pexpect.sourceforge.net/
COMMENT=	Pure Python Expect-like module
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-ptyprocess>=0.5:../../sysutils/py-ptyprocess

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
