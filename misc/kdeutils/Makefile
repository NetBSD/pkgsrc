# $NetBSD: Makefile,v 1.34 1999/12/06 21:00:12 bouyer Exp $
# FreeBSD Id: Makefile,v 1.4 1997/11/28 00:04:18 se Exp
#

DISTNAME=	kdeutils-1.1.2
CATEGORIES=	misc kde
MASTER_SITES=	ftp://ftp.us.kde.org/pub/kde/stable/1.1.2/distribution/tar/generic/source/bz2/ \
		ftp://ftp.de.kde.org/pub/kde/stable/1.1.2/distribution/tar/generic/source/bz2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.kde.org/

DEPENDS+=	kdebase-1.1.2:../../x11/kdebase

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--with-qt-dir=${PREFIX}" \
		"--with-qt-includes=${PREFIX}/include/qt"
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib"

.include "../../mk/bsd.pkg.mk"
