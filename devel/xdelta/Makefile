# $NetBSD: Makefile,v 1.4 1998/10/04 18:34:19 tron Exp $
#

DISTNAME=	xdelta-0.22
CATEGORIES=	devel
MASTER_SITES=	ftp://www.xcf.berkeley.edu/pub/xdelta/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://scam.XCF.Berkeley.EDU/~jmacd/xdelta.html

DEPENDS+=	glib-1.1.3:../../devel/glib
DEPENDS+=	gdbm-1.7.3:../../databases/gdbm

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
