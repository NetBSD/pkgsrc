# $NetBSD: Makefile,v 1.1.1.1 1999/01/17 09:31:28 frueauf Exp $
#

DISTNAME=		ntesla-1.7
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/circuits

MAINTAINER=		mcmahill@alum.mit.edu
HOMEPAGE=		http://www.nic.funet.fi/pub/sci/electrical/tesla/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ntesla ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
