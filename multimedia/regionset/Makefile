# $NetBSD: Makefile,v 1.1.1.1 2005/04/16 06:51:26 rumble Exp $
#

DISTNAME=		regionset-0.1
CATEGORIES=		multimedia
MASTER_SITES=		http://linvdr.org/download/regionset/

MAINTAINER=		rumble@NetBSD.org
HOMEPAGE=		http://linvdr.org/download/regionset/
COMMENT=		Read and modify DVD drive region code

USE_BUILDLINK3=		yes
ONLY_FOR_PLATFORM+=	NetBSD-*-* OpenBSD-*-* Linux-*-*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/regionset ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
