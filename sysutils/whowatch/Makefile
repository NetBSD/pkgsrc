# $NetBSD: Makefile,v 1.6 2003/07/13 13:53:24 wiz Exp $
#

DISTNAME=	whowatch-1.4
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://wizard.ae.krakow.pl/~mike/download/ \
		http://janek.ae.krakow.pl/~suszyckm/download/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://wizard.ae.krakow.pl/~mike/\#whowatch
COMMENT=	interactive who-like program displaying real-time user information

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
