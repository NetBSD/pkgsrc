# $NetBSD: Makefile,v 1.12 1998/04/28 22:54:07 tron Exp $
# FreeBSD Id: Makefile,v 1.4 1997/11/28 00:04:18 se Exp
#

DISTNAME=	kdeutils-beta4-1
PKGNAME=	kdeutils-4.1b
CATEGORIES=	misc kde
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
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=${PREFIX}" \
		"--x-inc=${PREFX}/include -I${LOCALBASE}/include -I${LOCALBASE}/include/giflib" \
		"--x-lib=${PREFIX}/lib -L${LOCALBASE}/lib" \
		"--with-qt-dir=${PREFIX}" \
		"--with-qt-includes=${X11BASE}/include/qt"
CONFIGURE_ENV=	INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL="/usr/bin/install"

WRKSRC=		${WRKDIR}/kdeutils

.include "../../mk/bsd.pkg.mk"
