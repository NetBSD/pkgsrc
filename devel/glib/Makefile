# $NetBSD: Makefile,v 1.2 1998/08/19 09:41:38 agc Exp $
# FreeBSD Id: Makefile,v 1.2 1998/08/06 14:55:12 vanilla Exp
#

DISTNAME=	glib-1.1.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/v1.1/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.1/ \
		http://www.ameth.org/gimp/pub/gtk/v1.1/

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/glib
CONFIGURE_ENV+=		LIBTOOL="${LOCALBASE}/bin/libtool --install-la"

.include "../../mk/bsd.pkg.mk"
