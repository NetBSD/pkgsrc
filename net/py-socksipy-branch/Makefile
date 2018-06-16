# $NetBSD: Makefile,v 1.4 2018/06/16 20:33:21 bsiegert Exp $

DISTNAME=	SocksiPy-branch-1.01
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=     net
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SocksiPy-branch/}

MAINTAINER=     kethzer.dr@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/SocksiPy-branch/
COMMENT=        Python SOCKS module
LICENSE=        modified-bsd

CONFLICTS=	${PYPKGPREFIX}-Socks-[0-9]*

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
