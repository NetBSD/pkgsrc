# $NetBSD: Makefile,v 1.3 1999/03/09 09:10:05 agc Exp $
# FreeBSD Id: Makefile,v 1.2 1999/01/27 08:31:48 fenner Exp
#

DISTNAME=	audiofile-0.1.6
PKGNAME=	libaudiofile-0.1.6
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/gnome-1.0/sources/ \
		ftp://ftp.jimpick.com/pub/mirrors/gnome/gnome-1.0/sources/ \
		ftp://ftp.informatik.uni-bonn.de/pub/os/unix/gnome/gnome-1.0/sources/

MAINTAINER=	tron@netbsd.org

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

.include <../../mk/bsd.pkg.mk>
