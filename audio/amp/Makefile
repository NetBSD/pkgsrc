# New ports collection makefile for:	amp
# Version required:	0.7.6
# Date created:		Jun 23 1997
# Whom:			Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $NetBSD: Makefile,v 1.3 1998/01/08 17:11:15 agc Exp $
# FreeBSD Id: Makefile,v 1.2 1997/09/03 08:35:30 max Exp 
#

DISTNAME=	amp-0.7.6
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.rasip.fer.hr/pub/mpeg/
EXTRACT_SUFX=	.tgz

# FreeBSD maintainer
MAINTAINER=	vanilla@MinJe.com.TW

GNU_CONFIGURE=	yes

MAN1=		amp.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/amp ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/amp.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
