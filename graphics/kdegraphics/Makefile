# $NetBSD: Makefile,v 1.2 1998/05/04 00:20:02 tron Exp $
#

DISTNAME=	kdegraphics-beta4-1
PKGNAME=	kdegraphics-4.1b
CATEGORIES=	graphics kde
MASTER_SITES=	ftp://ftp.appl-opt.physik.uni-essen.de/pub/linux/kde/stable/Beta4/distribution/tgz/source/ \
		ftp://ftp.net.lut.ac.uk/kde/stable/Beta4/distribution/tgz/source/ \
 		ftp://ftp.caldera.com/pub/mirrors/kde/stable/Beta4/distribution/tgz/source/
EXTRACT_SUFX=	.src.tar.bz2

MAINTAINER=	tron@netbsd.org

BUILD_DEPENDS=	bzip2:../../archivers/bzip2 \
		moc:../../x11/qt
DEPENDS+=	giflib-3.0:../../graphics/giflib
DEPENDS+=	jpeg-6a:../../graphics/jpeg
DEPENDS+=	qt-1.33:../../x11/qt
DEPENDS+=	kdelibs-4.1b:../../x11/kdelibs
DEPENDS+=	kdebase-4.1b:../../x11/kdebase

EXTRACT_CMD=		bzip2
EXTRACT_BEFORE_ARGS=	-d <
EXTRACT_AFTER_ARGS=	| pax -r

USE_X11=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--x-inc=${PREFIX}/include -I${LOCALBASE}/include -I${LOCALBASE}/include/giflib" \
		"--x-lib=${PREFIX}/lib -L${LOCALBASE}/lib" \
		"--datadir=${PREFIX}/share/kde" \
		"--with-qt-dir=${PREFIX}" \
		"--with-qt-includes=${PREFIX}/include/qt"
CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL="/usr/bin/install"

WRKSRC=		${WRKDIR}/kdegraphics

.include "../../mk/bsd.pkg.mk"
