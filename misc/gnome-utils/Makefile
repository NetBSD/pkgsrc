# $NetBSD: Makefile,v 1.7 1999/07/23 09:17:04 tron Exp $
#

DISTNAME=	gnome-utils-1.0.1
CATEGORIES=	misc x11 gnome
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/gnome-1.0/sources/ \
		ftp://ftp.tuwien.ac.at/hci/GNOME/gnome-1.0/sources/ \
		ftp://gnomeftp.wgn.net/pub/gnome/ \
		ftp://ftp.informatik.uni-bonn.de/pub/os/unix/gnome/ \
		ftp://unix.hensa.ac.uk/mirrors/ftp.gnome.org/pub/GNOME/ \
		ftp://ftp.sunet.se/pub/X11/GNOME/ \
		ftp://ftp.dataplus.se/pub/linux/gnome/ \
		ftp://ftp.net.lut.ac.uk/gnome/ \
		ftp://mirror.aarnet.edu.au/pub/gnome/ \
		ftp://ftp.fr.gnome.org/pub/gnome/ \
		ftp://ftp.dti.ad.jp/pub/X/GNOME/ \
		http://gd.tuwien.ac.at/hci/GNOME/gnome-1.0/sources/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

BUILD_DEPENDS=	${LOCALBASE}/bin/bison:../../devel/bison
DEPENDS+=	ncurses-4.2:../../devel/ncurses
DEPENDS+=	gnome-core-1.0.7:../../x11/gnome-core

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
CONFIGURE_ENV+=	XGETTEXT="${LOCALBASE}/bin/xgettext"
CONFIGURE_ARGS=	--with-ncurses=${LOCALBASE}

.include "../../mk/bsd.pkg.mk"
