# $NetBSD: Makefile,v 1.22 2000/03/16 12:17:21 wiz Exp $
# FreeBSD Id: Makefile,v 1.2 1998/08/06 14:55:12 vanilla Exp
#

DISTNAME=	glib-1.2.7
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/v1.2/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.2/ \
		http://www.ameth.org/gimp/pub/gtk/v1.2/ \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gtk/v1.2/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gtk.org/docs/glib_toc.html

DEPENDS+=	pth>=1.3.2:../pth

CONFLICTS=	gtk+-1.0.*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=--includedir=${PREFIX}/include/glib
LIBTOOL_FLAGS=	 --install-la
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"

INFO_FILES=	glib.info

# XXX egcs is still broken on arm32.
.if (${MACHINE_ARCH} == arm32)
CFLAGS=		-O0
.endif

.include "../../mk/bsd.pkg.mk"
