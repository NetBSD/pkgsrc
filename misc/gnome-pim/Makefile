# $NetBSD: Makefile,v 1.1.1.1 1999/05/03 16:38:44 rh Exp $
#

DISTNAME=	gnome-pim-1.0.7
CATEGORIES=	misc x11
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
DEPENDS+=	gettext-0.10.35:../../devel/gettext
DEPENDS+=	gnome-libs-1.0.9:../../x11/gnome-libs
DEPENDS+=	libaudiofile-0.1.6:../../audio/libaudiofile

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

.include "../../mk/bsd.pkg.mk"
