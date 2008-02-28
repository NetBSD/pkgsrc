# $NetBSD: Makefile,v 1.13 2008/02/28 11:58:48 rillig Exp $

DISTNAME=	zombies-1.0
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.thistledown.com.au/software/

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	http://www.thistledown.com.au/software/
COMMENT=	Simple robots-like game where you destroy the zombies

AUTO_MKDIRS=			yes
BUILD_DEFS+=		VARBASE
MAKE_ENV+=	VARBASE=${VARBASE}
MAKE_DIRS=	${VARBASE}/games

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
