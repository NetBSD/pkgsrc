# $NetBSD: Makefile,v 1.5 2018/08/22 06:20:30 adam Exp $

DISTNAME=	SocksiPy-branch-1.01
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SocksiPy-branch/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	http://code.google.com/p/socksipy-branch/
COMMENT=	Python SOCKS module
LICENSE=	modified-bsd

CONFLICTS=	${PYPKGPREFIX}-Socks-[0-9]*

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
