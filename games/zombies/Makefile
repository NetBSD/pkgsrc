# $NetBSD: Makefile,v 1.7 2005/04/01 03:07:57 reed Exp $

DISTNAME=	zombies-1.0
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.thistledown.com.au/software/ \
		ftp://melanoma.cs.rmit.edu.au/pub/simonb/

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	http://www.thistledown.com.au/software/
COMMENT=	Simple robots-like game where you destroy the zombies

USE_BUILDLINK3=		yes
INSTALLATION_DIRS=	bin man/man6 share/games

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
