# $NetBSD: Makefile,v 1.11 1998/07/28 10:49:49 frueauf Exp $
# FreeBSD Id: Makefile,v 1.5 1997/04/20 13:19:30 wosch Exp
#

DISTNAME=	dotfile-2.0
CATEGORIES=	misc tk80
MASTER_SITES=	ftp://ftp.imada.ou.dk/pub/dotfile/

MAINTAINER=	oly@world.std.com

DEPENDS+=	tk-8.0p2:../../x11/tk80
RUN_DEPENDS=	wish8.0:../../x11/tk80

# this pkg opens some X connectin
IS_INTERACTIVE= yes

GNU_CONFIGURE=	yes

do-build:
	@${DO_NADA}

.include "../../mk/bsd.pkg.mk"
