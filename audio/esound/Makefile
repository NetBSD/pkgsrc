# $NetBSD: Makefile,v 1.3 1999/03/06 22:45:16 tron Exp $

DISTNAME=	esound-0.2.8
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/sources/gnome-1.0/sources/ \
		ftp://ftp.jimpick.com/pub/mirrors/gnome/gnome-1.0/sources/ \
		ftp://ftp.informatik.uni-bonn.de/pub/os/unix/gnome/gnome-1.0/sources/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://pw1.netcom.com/~ericmit/EsounD.html

DEPENDS+=	libaudiofile-0.1.6:../../audio/libaudiofile

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

.include "../../mk/bsd.pkg.mk"
