# $NetBSD: Makefile,v 1.13 2000/06/01 11:23:25 rh Exp $
#

DISTNAME=	xdelta-0.22
CATEGORIES=	devel
MASTER_SITES=	ftp://www.xcf.berkeley.edu/pub/xdelta/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://scam.XCF.Berkeley.EDU/~jmacd/xdelta.html

DEPENDS+=	glib-1.2.*:../../devel/glib
DEPENDS+=	gdbm-1.7.3:../../databases/gdbm

USE_PKGLIBTOOL=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	"-L${LOCALBASE}/lib"
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
