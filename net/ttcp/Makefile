# New ports collection makefile for:	ttcp
# Version required:	???
# Date created:		14 December 1997
# Whom:			thorpej
#
# $NetBSD: Makefile,v 1.3 1998/01/24 21:55:14 hubertf Exp $
#

DISTNAME=	ttcp
CATEGORIES=	net
MASTER_SITES=	http://www.ccci.com/tools/ttcp/
EXTRACT_SUFX=	.tar

MAINTAINER=	thorpej@NetBSD.ORG

EXTRACT_CMD=	${MKDIR} ttcp; tar
EXTRACT_BEFORE_ARGS=-C ttcp -xf

MAN1=		ttcp.1

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttcp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ttcp.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
