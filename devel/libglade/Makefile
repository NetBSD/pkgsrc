# $NetBSD: Makefile,v 1.2 1999/08/27 14:31:02 rh Exp $
#

DISTNAME=	libglade-0.4
CATEGORIES=	devel
MASTER_SITES=	http://gd.tuwien.ac.at/hci/gnome.org/GNOME/sources/libglade/ \
		ftp://gnomeftp.wgn.net/pub/gnome/sources/libglade/ \
		ftp://ftp.fr.gnome.org/pub/gnome/sources/libglade/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.daa.com.au/~james/gnome/

DEPENDS+=	mawk-1.2.2:../../lang/mawk
DEPENDS+=	gnome-libs-1.0.10:../../x11/gnome-libs
DEPENDS+=	libxml-1.4.0:../../textproc/libxml

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_X11BASE=	YES
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
