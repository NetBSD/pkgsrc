# $NetBSD: Makefile,v 1.8 1998/05/08 22:43:37 hubertf Exp $
# FreeBSD Id: Makefile,v 1.5 1997/04/20 13:19:30 wosch Exp
#

DISTNAME=	dotfile-2.0
CATEGORIES=	misc tk80
MASTER_SITES=	ftp://ftp.imada.ou.dk/pub/dotfile/

MAINTAINER=	oly@world.std.com

DEPENDS+=	tk-8.0p2:../../x11/tk80
RUN_DEPENDS=	wish8.0:../../x11/tk80

# this pkg opens some X connectin
.ifndef DISPLAY
IS_INTERACTIVE= yes
.endif
GNU_CONFIGURE=	yes
MAN1=		dotfile.1

do-build:
	@${DO_NADA}

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include "../../mk/bsd.pkg.mk"
