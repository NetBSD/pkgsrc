# $NetBSD: Makefile,v 1.9 1998/07/14 22:56:40 tron Exp $
# FreeBSD Id: Makefile,v 1.2 1997/11/05 04:19:46 asami Exp
#

DISTNAME=	kdesupport-1.0
CATEGORIES=	converters kde
MASTER_SITES=	ftp://ftp.us.kde.org/pub/kde/stable/1.0/distribution/tar/generic/source/ \
		ftp://ftp.kde.org/pub/kde/stable/1.0/distribution/tar/generic/source/

MAINTAINER=	tron@netbsd.org

DEPENDS+=	qt-1.33:../../x11/qt

CONFLICTS=	kdesupport-2.1b kdesupport-3.1b kdesupport-4.1b

USE_X11=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=${PREFIX}" \
		"--datadir=${PREFIX}/share/kde" \
		"--with-qt-includes=${X11BASE}/include/qt" \
		"--with-qt-libraries=${X11BASE}/lib" \
		"--without-gnu-ld" \
		"--without-libjpeg" \
		"--without-libgif" \
		"--without-libgdbm" \
		"--without-libuulib"

.include "../../mk/bsd.pkg.mk"
