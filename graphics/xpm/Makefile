# $NetBSD: Makefile,v 1.9 1998/06/22 12:39:48 agc Exp $
# FreeBSD Id: Makefile,v 1.14 1997/07/17 15:12:45 max Exp
#

DISTNAME=       xpm-3.4j
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://avahi.inria.fr/pub/xpm/

MAINTAINER=	packages@netbsd.org

USE_IMAKE=	yes

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
