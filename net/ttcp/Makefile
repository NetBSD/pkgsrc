#	$NetBSD: Makefile,v 1.1 1997/12/14 23:59:26 thorpej Exp $
#
# New ports collection makefile for:	ttcp
# Version required:	???
# Date created:		14 December 1997
# Whom:			thorpej
#

DISTNAME=	ttcp
CATEGORIES=	net
MASTER_SITES=	http://www.ccci.com/tools/ttcp/
DISTFILES=	ttcp.tar

EXTRACT_CMD=	mkdir ttcp; tar
EXTRACT_SUFX=	.tar
EXTRACT_BEFORE_ARGS=-C ttcp -xf

MAINTAINER=	thorpej@NetBSD.ORG

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttcp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ttcp.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
