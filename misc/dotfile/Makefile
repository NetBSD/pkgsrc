# $NetBSD: Makefile,v 1.13 1998/11/19 15:40:46 agc Exp $
# FreeBSD Id: Makefile,v 1.5 1997/04/20 13:19:30 wosch Exp
#

DISTNAME=	dotfile-2.0
CATEGORIES=	misc tk80
MASTER_SITES=	ftp://ftp.imada.ou.dk/pub/dotfile/

MAINTAINER=	oly@world.std.com
HOMEPAGE=	http://www.imada.ou.dk/~blackie/dotfile/

DEPENDS+=	tk-8.0p2:../../x11/tk80

# this pkg opens some X connectin
IS_INTERACTIVE= yes

GNU_CONFIGURE=	yes

do-build:
	@${DO_NADA}

.include "../../mk/bsd.pkg.mk"
