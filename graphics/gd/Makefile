# $NetBSD: Makefile,v 1.6 1998/08/20 15:17:00 tsarna Exp $
# FreeBSD Id: Makefile,v 1.2 1997/02/14 07:55:45 asami Exp
#

DISTNAME=       gd1.3
PKGNAME=        gd-1.3
CATEGORIES=	graphics
MASTER_SITES=   ftp://www.boutell.com/pub/boutell/gd/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.boutell.com/gd/

pre-install:
	${MKDIR} ${PREFIX}/include/gd
	${MKDIR} ${PREFIX}/share/examples/gd

.include "../../mk/bsd.pkg.mk"
