# $NetBSD: Makefile,v 1.2 1999/04/15 20:39:40 tron Exp $
#

DISTNAME=		ntesla-1.7
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SUNSITE:=apps/circuits/}

MAINTAINER=		mcmahill@alum.mit.edu
HOMEPAGE=		http://www.nic.funet.fi/pub/sci/electrical/tesla/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ntesla ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
