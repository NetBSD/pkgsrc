# $NetBSD: Makefile,v 1.11 2004/04/18 23:35:35 snj Exp $
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
USE_BUILDLINK3=	YES

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
