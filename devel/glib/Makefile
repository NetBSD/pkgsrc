# $NetBSD: Makefile,v 1.7 1998/11/21 16:57:29 tron Exp $
# FreeBSD Id: Makefile,v 1.2 1998/08/06 14:55:12 vanilla Exp
#

DISTNAME=	glib-1.1.4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/v1.1/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.1/ \
		http://www.ameth.org/gimp/pub/gtk/v1.1/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gtk.org/docs/glib_toc.html

CONFLICTS=	glib-1.1.2 glib-1.1.3 gtk+-1.0.4

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

INFO_FILES=	glib.info

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/glib
LIBTOOL_FLAGS=	 --install-la

.include "../../mk/bsd.pkg.mk"
