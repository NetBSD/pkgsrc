# $NetBSD: Makefile,v 1.5 1999/05/20 20:09:49 tron Exp $

DISTNAME=	esound-0.2.8
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/gnome-1.0/sources/ \
		ftp://ftp.jimpick.com/pub/mirrors/gnome/gnome-1.0/sources/ \
		ftp://ftp.informatik.uni-bonn.de/pub/os/unix/gnome/gnome-1.0/sources/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://pw1.netcom.com/~ericmit/EsounD.html

DEPENDS+=	libaudiofile-0.1.6:../../audio/libaudiofile

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
