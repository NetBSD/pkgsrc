# $NetBSD: Makefile,v 1.2 2019/09/24 09:04:08 adam Exp $

DISTNAME=	Pyinotify-0.9.6
PKGNAME=	${PYPKGPREFIX}-pyinotify-0.9.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=seb-m/}
GITHUB_PROJECT=	pyinotify
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/seb-m/pyinotify
COMMENT=	Python inotify library
LICENSE=	mit

EGG_NAME=	${DISTNAME:tl}

.include "../../devel/libinotify/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
