# $NetBSD: Makefile,v 1.9 2026/01/30 09:14:20 wiz Exp $

DISTNAME=	SocksiPy-branch-1.01
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SocksiPy-branch/}

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://code.google.com/archive/p/socksipy-branch/
COMMENT=	Python SOCKS module
LICENSE=	modified-bsd

CONFLICTS=	py[0-9]*-Socks-[0-9]*

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} != "py27"
EGG_NAME=	SocksiPy_branch-1.1
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
