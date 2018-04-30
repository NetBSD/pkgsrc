# $NetBSD: Makefile,v 1.1 2018/04/30 04:56:17 ryoon Exp $

DISTNAME=	mypaint-brushes-1.3.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=Jehan/}
GITHUB_PROJECT=	mypaint-brushes
GITHUB_TAG=	v1.3.0

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/Jehan/mypaint-brushes/
COMMENT=	Default MyPaint brushes
LICENSE=	cc0-1.0-universal

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	pkgconfig.pc.in

SCONS_ARGS+=	prefix=${DESTDIR}${PREFIX}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons \
		${SCONS_ARGS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons \
		${SCONS_ARGS} install

.include "../../mk/bsd.pkg.mk"
