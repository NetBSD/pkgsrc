# $NetBSD: Makefile,v 1.7 1998/04/28 22:52:32 tron Exp $
# FreeBSD Id: Makefile,v 1.2 1997/11/05 04:19:46 asami Exp
#

DISTNAME=	kdesupport-beta4-1
PKGNAME=	kdesupport-4.1b
CATEGORIES=	converters kde
MASTER_SITES=	ftp://ftp.appl-opt.physik.uni-essen.de/pub/linux/kde/stable/Beta4/distribution/tgz/source/ \
		ftp://ftp.net.lut.ac.uk/kde/stable/Beta4/distribution/tgz/source/ \
 		ftp://ftp.caldera.com/pub/mirrors/kde/stable/Beta4/distribution/tgz/source/
EXTRACT_SUFX=	.src.tar.bz2

MAINTAINER=	tron@netbsd.org

BUILD_DEPENDS=	bzip2:../../archivers/bzip2
DEPENDS+=	qt-1.33:../../x11/qt

EXTRACT_CMD=		bzip2
EXTRACT_BEFORE_ARGS=	-d <
EXTRACT_AFTER_ARGS=	| pax -r

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

WRKSRC=		${WRKDIR}/kdesupport

.include "../../mk/bsd.pkg.mk"
