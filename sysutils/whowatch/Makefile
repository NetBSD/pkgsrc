# $NetBSD: Makefile,v 1.4.2.1 2002/06/30 06:24:16 jlam Exp $
#

DISTNAME=	whowatch-1.4
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
