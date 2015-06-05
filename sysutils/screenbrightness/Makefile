# $NetBSD: Makefile,v 1.2 2015/06/05 14:43:48 wiedi Exp $

DISTNAME=	screenbrightness-1.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=jmstacey/}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/jmstacey/screenbrightness/
COMMENT=	Command-line display brightness control for OS X
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c99
USE_TOOLS+=	gmake
BUILD_TARGET=	build
MAKE_ENV+=	DESTDIR=${DESTDIR}

ONLY_FOR_PLATFORM=	Darwin-*-*

.include "../../mk/bsd.pkg.mk"
