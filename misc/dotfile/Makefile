# $NetBSD: Makefile,v 1.5 1998/04/15 10:38:34 agc Exp $
# FreeBSD Id: Makefile,v 1.5 1997/04/20 13:19:30 wosch Exp
#

DISTNAME=	dotfile-2.0
CATEGORIES=	misc tk80
MASTER_SITES=	ftp://ftp.imada.ou.dk/pub/dotfile/

MAINTAINER=	oly@world.std.com

LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11/tk80
RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11/tk80

GNU_CONFIGURE=	yes
MAN1=		dotfile.1

do-build:
	@${DO_NADA}

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include "../../mk/bsd.pkg.mk"
