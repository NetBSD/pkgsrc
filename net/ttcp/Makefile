# New ports collection makefile for:	ttcp
# Version required:	???
# Date created:		14 December 1997
# Whom:			thorpej
#
# $NetBSD: Makefile,v 1.7 1998/03/05 15:18:23 tron Exp $
#

DISTNAME=	ttcp
PKGNAME=	${DISTNAME}-1.12
CATEGORIES=	net
MASTER_SITES=	http://www.ccci.com/tools/ttcp/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	thorpej@NetBSD.ORG

NO_CONFIGURE=	yes
NO_WRKSUBDIR=	yes

MAN1=		ttcp.1

# MANZ is handled automatically
.if defined(MANZ)
MANCOMPRESSED=	1
.endif

.include <bsd.port.mk>
