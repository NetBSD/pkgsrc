# New ports collection makefile for:	ttcp
# Version required:	???
# Date created:		14 December 1997
# Whom:			thorpej
#
# $NetBSD: Makefile,v 1.4 1998/02/27 00:02:51 tron Exp $
#

DISTNAME=	ttcp
CATEGORIES=	net
MASTER_SITES=	http://www.ccci.com/tools/ttcp/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	thorpej@NetBSD.ORG

NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}

MAN1=		ttcp.1

real-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttcp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ttcp.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
