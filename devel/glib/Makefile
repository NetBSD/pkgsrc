# $NetBSD: Makefile,v 1.13 1999/03/04 08:50:43 tron Exp $
# FreeBSD Id: Makefile,v 1.2 1998/08/06 14:55:12 vanilla Exp
#

DISTNAME=	glib-1.2.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/v1.2/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.2/ \
		http://www.ameth.org/gimp/pub/gtk/v1.2/ \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gtk/v1.2/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gtk.org/docs/glib_toc.html

CONFLICTS=	gtk+-1.0.*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

INFO_FILES=	glib.info

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/glib
LIBTOOL_FLAGS=	 --install-la

.include "../../mk/bsd.pkg.mk"
