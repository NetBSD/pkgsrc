# $NetBSD: Makefile,v 1.2 2018/04/30 20:56:11 wiz Exp $

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

BUILD_DEPENDS+=	scons-[0-9]*:../../devel/scons

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
