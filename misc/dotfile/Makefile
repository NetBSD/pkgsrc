# New ports collection makefile for: dotfile
# Version required:  2.0
# Date created:      11/12/96
# Whom:              oly@world.std.com
#
# $Id: Makefile,v 1.1.1.1 1997/10/11 21:54:11 hubertf Exp $
#

DISTNAME=	dotfile-2.0
CATEGORIES=	misc tk41
MASTER_SITES=	ftp://ftp.imada.ou.dk/pub/dotfile/

MAINTAINER=	oly@world.std.com

LIB_DEPENDS=	tk41\\.1:${PORTSDIR}/x11/tk41
RUN_DEPENDS=	wish4.1:${PORTSDIR}/x11/tk41

GNU_CONFIGURE=	yes
MAN1=		dotfile.1

do-build:
	@${DO_NADA}

post-install:
	@${CAT} ${PKGDIR}/MESSAGE
	
.include <bsd.port.mk>
