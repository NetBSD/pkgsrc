# $NetBSD: Makefile,v 1.20 2017/11/10 07:51:58 adam Exp $

DISTNAME=	pexpect-4.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pexpect/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://pexpect.sourceforge.net/
COMMENT=	Pure Python Expect-like module
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-ptyprocess-[0-9]*:../../sysutils/py-ptyprocess

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
