# $NetBSD: Makefile,v 1.1 2018/10/04 15:46:48 roy Exp $
#

DISTNAME=	AitDoB-0.0.20120330
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=jaldhar/}
GITHUB_TAG=	facbecc3cd621efabfcfe5a910cb2da70745fe46

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaldhar/AitDoB
COMMENT=	Ascent into the Depths of Beyond -- A roguelike game
LICENSE=	public-domain

USE_CURSES=	ripoffline
USE_LANGUAGES=	c++

BUILD_TARGET=	aitdob
LDFLAGS+=	-l${BUILDLINK_LIBNAME.curses}

# Install to /usr/pkg/bin
MAKE_ENV+=	GAMESDIR=/bin

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
