# $NetBSD: Makefile,v 1.7 1999/05/03 20:25:36 tv Exp $
#

DISTNAME=	fly-1.6.1
CATEGORIES=	graphics www
MASTER_SITES=	ftp://www.unimelb.edu.au/pub/www/tools/unix/fly/

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.unimelb.edu.au/fly/fly.html

DEPENDS+=	gd-1.3p1:../../graphics/gd

do-install:
	${MKDIR} ${PREFIX}/share/doc/fly
	${MKDIR} ${PREFIX}/share/examples/fly
	${INSTALL_PROGRAM} ${WRKSRC}/fly ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/fly
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/fly

.include "../../mk/bsd.pkg.mk"
