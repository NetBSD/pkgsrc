# $NetBSD: Makefile,v 1.21 1999/07/07 21:57:31 tron Exp $
#

DISTNAME=	kdegraphics-1.1.1
CATEGORIES=	graphics kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/1.1.1/distribution/tar/generic/source/bz2/ \
		ftp://ftp.de.kde.org/pub/kde/stable/1.1.1/distribution/tar/generic/source/bz2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.kde.org/

DEPENDS+=	kdebase-1.1.1:../../x11/kdebase

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--x-inc=${PREFIX}/include -I${LOCALBASE}/include -I${LOCALBASE}/include/giflib" \
		"--x-lib=${PREFIX}/lib -L${LOCALBASE}/lib" \
		"--datadir=${PREFIX}/share/kde" \
		"--with-qt-dir=${PREFIX}" \
		"--with-qt-includes=${PREFIX}/include/qt"
CFLAGS+=	-I${LOCALBASE}/include/giflib -I${LOCALBASE}/include
CONFIGURE_ENV=  KDEDIR=${PREFIX} \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib"

.include "../../mk/bsd.pkg.mk"
