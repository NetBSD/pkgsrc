# $NetBSD: Makefile,v 1.1 2015/01/17 15:34:21 wiedi Exp $

VERSION=	1.1
DISTNAME=	${VERSION}
PKGNAME=	screenbrightness-${VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/jmstacey/screenbrightness/archive/

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/jmstacey/screenbrightness/
COMMENT=	Command-line display brightness control for OS X
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/screenbrightness-${VERSION}
USE_TOOLS+=	gmake
BUILD_TARGET=	build
MAKE_ENV+=	DESTDIR=${DESTDIR}

ONLY_FOR_PLATFORM=	Darwin-*-*

.include "../../mk/bsd.pkg.mk"
