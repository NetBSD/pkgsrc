# $NetBSD: Makefile,v 1.30 2000/07/11 14:53:38 agc Exp $
# FreeBSD Id: Makefile,v 1.2 1997/11/05 04:19:46 asami Exp
#

DISTNAME=	kdesupport-1.1.2
CATEGORIES=	converters kde
MASTER_SITES=	ftp://ftp.us.kde.org/pub/kde/stable/1.1.2/distribution/tar/generic/source/bz2/ \
		ftp://ftp.de.kde.org/pub/kde/stable/1.1.2/distribution/tar/generic/source/bz2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.kde.org/

USE_PKGLIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--without-gnu-ld" \
		"--without-libjpeg" \
		"--without-libgif" \
		"--without-libgdbm" \
		"--without-libuulib" \
		"--without-sprite-field" \
		"--with-qt-dir=`${MAKE} show-qt1-prefix`/qt1" 

.include "../../mk/bsd.pkg.mk"
