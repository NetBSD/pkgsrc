# $NetBSD: Makefile,v 1.11 1998/04/24 09:20:36 agc Exp $
# FreeBSD Id: Makefile,v 1.4 1997/11/28 00:04:18 se Exp
#

DISTNAME=	kdeutils-Beta3-1
PKGNAME=	kdeutils-3.1b
CATEGORIES=	misc kde
MASTER_SITES=	ftp://ftp.net.lut.ac.uk/kde/stable/Beta3/distribution/tgz/source/ \
 		ftp://ftp.uni-erlangen.de/pub/Linux/MIRROR.KDE/stable/Beta3/distribution/tgz/source/ \
 		ftp://ftp.caldera.com/pub/mirrors/kde/stable/Beta3/distribution/tgz/source/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	packages@netbsd.org

BUILD_DEPENDS=	moc:../../x11/qt
DEPENDS+=	jpeg-6a:../../graphics/jpeg
DEPENDS+=	qt-1.33:../../x11/qt
DEPENDS+=	kdelibs-3.1b:../../x11/kdelibs
DEPENDS+=	giflib-3.0:../../graphics/giflib
RUN_DEPENDS=	kappfinder:../../x11/kdebase

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
