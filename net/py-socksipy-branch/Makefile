# $NetBSD: Makefile,v 1.6 2022/01/10 08:47:45 wiz Exp $

DISTNAME=	SocksiPy-branch-1.01
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SocksiPy-branch/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	http://code.google.com/p/socksipy-branch/
COMMENT=	Python SOCKS module
LICENSE=	modified-bsd

CONFLICTS=	${PYPKGPREFIX}-Socks-[0-9]*

EGG_NAME=	SocksiPy_branch-1.1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
