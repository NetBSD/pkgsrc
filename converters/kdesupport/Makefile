# $NetBSD: Makefile,v 1.15 1998/09/27 18:06:41 tron Exp $
# FreeBSD Id: Makefile,v 1.2 1997/11/05 04:19:46 asami Exp
#

DISTNAME=	kdesupport-1.0
CATEGORIES=	converters kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/1.0/distribution/tar/generic/source/ \
		ftp://ftp.de.kde.org/pub/kde/stable/1.0/distribution/tar/generic/source/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.kde.org/

DEPENDS+=	qt-1.40:../../x11/qt

CONFLICTS=	kdesupport-2.1b kdesupport-3.1b kdesupport-4.1b

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
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
