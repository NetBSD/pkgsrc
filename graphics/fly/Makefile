# $NetBSD: Makefile,v 1.3 1998/07/01 17:01:45 tron Exp $
#

DISTNAME=       fly-1.6.1
CATEGORIES=	graphics www
MASTER_SITES=   ftp://www.unimelb.edu.au/pub/www/tools/unix/fly/

MAINTAINER=	bouyer@netbsd.org

DEPENDS+=       gd-1.3:../../graphics/gd

CONFLICTS=	fly-1.6.0

pre-install:
	${MKDIR} ${PREFIX}/share/doc/fly
	${MKDIR} ${PREFIX}/share/examples/fly
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fly ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/fly
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/fly

.include "../../mk/bsd.pkg.mk"
