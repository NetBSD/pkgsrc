# $NetBSD: Makefile,v 1.9 2003/09/27 17:07:38 grant Exp $
#

DISTNAME=	whowatch-1.4
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://wizard.ae.krakow.pl/~mike/download/ \
		http://janek.ae.krakow.pl/~suszyckm/download/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://wizard.ae.krakow.pl/~mike/\#whowatch
COMMENT=	Interactive who-like program displaying real-time user information

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

.include "../../mk/curses.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
