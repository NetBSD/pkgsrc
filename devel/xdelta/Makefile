#
# $NetBSD: Makefile,v 1.1 1998/08/22 13:40:38 garbled Exp $
#

DISTNAME=		xdelta-0.22
CATEGORIES=		devel
MASTER_SITES=		ftp://www.xcf.berkeley.edu/pub/xdelta/

MAINTAINER=		root@garbled.net

DEPENDS+=		glib-1.1.2:../../devel/glib
DEPENDS+=		gdbm-1.7.3:../../databases/gdbm
DEPENDS+=		libtool-1.2:../../devel/libtool

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LDFLAGS="-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
