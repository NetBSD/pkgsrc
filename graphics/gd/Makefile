# $NetBSD: Makefile,v 1.4 1998/04/15 10:38:25 agc Exp $
# FreeBSD Id: Makefile,v 1.2 1997/02/14 07:55:45 asami Exp
#

DISTNAME=       gd1.2
PKGNAME=        gd-1.2
CATEGORIES=	graphics
MASTER_SITES=   http://www.boutell.com/gd/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	packages@netbsd.org

pre-install:
	${MKDIR} ${PREFIX}/include/gd
	${MKDIR} ${PREFIX}/share/examples/gd

.include "../../mk/bsd.pkg.mk"
