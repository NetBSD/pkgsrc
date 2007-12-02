# $NetBSD: Makefile,v 1.11 2007/12/02 00:04:08 wiz Exp $

DISTNAME=	zombies-1.0
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.thistledown.com.au/software/

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	http://www.thistledown.com.au/software/
COMMENT=	Simple robots-like game where you destroy the zombies

INSTALLATION_DIRS_FROM_PLIST=	yes
BUILD_DEFS+=		VARBASE
MAKE_ENV+=	VARBASE=${VARBASE}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
