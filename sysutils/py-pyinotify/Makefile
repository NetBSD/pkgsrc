# $NetBSD: Makefile,v 1.3 2022/01/04 20:54:49 wiz Exp $

DISTNAME=	Pyinotify-0.9.6
PKGNAME=	${PYPKGPREFIX}-pyinotify-0.9.6
PKGREVISION=	1
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
