# $NetBSD: Makefile,v 1.20 1999/02/15 22:34:57 tron Exp $
# FreeBSD Id: Makefile,v 1.2 1997/11/05 04:19:46 asami Exp
#

DISTNAME=	kdesupport-1.1
CATEGORIES=	converters kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/1.1/distribution/tar/generic/source/bz2/ \
		ftp://ftp.de.kde.org/pub/kde/stable/1.1/distribution/tar/generic/source/bz2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.kde.org/

DEPENDS+=	qt-1.42:../../x11/qt

CONFLICTS=	kdesupport-*

USE_X11BASE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--datadir=${PREFIX}/share/kde" \
		"--with-qt-includes=${PREFIX}/include/qt" \
		"--with-qt-libraries=${PREFIX}/lib" \
		"--without-gnu-ld" \
		"--without-libjpeg" \
		"--without-libgif" \
		"--without-libgdbm" \
		"--without-libuulib"
LIBTOOL_FLAGS=	--install-la

.include "../../mk/bsd.pkg.mk"
