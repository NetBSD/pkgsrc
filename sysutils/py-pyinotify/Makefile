# $NetBSD: Makefile,v 1.1 2018/06/12 01:00:56 youri Exp $

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

EGG_NAME=	pyinotify-${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../devel/libinotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
