# $NetBSD: Makefile,v 1.20 1999/06/19 15:19:12 tron Exp $
#

DISTNAME=	ORBit-0.4.3
CATEGORIES=	corba
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/gnome-1.0/sources/ \
		ftp://ftp.sunet.se/pub/X11/GNOME/gnome-1.0/sources/ \
		ftp://ftp.informatik.uni-bonn.de/pub/os/unix/gnome/gnome-1.0/sources/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	glib-1.2.2:../../devel/glib
DEPENDS+=	gindent-1.9.1:../../devel/gindent

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes

LIBTOOL_FLAGS=	--install-la
INFO_FILES=	libIDL.info

.include "../../mk/bsd.pkg.mk"
