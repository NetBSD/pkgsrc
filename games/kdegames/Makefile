# $NetBSD: Makefile,v 1.33 1999/09/15 18:26:01 tron Exp $
# FreeBSD Id: Makefile,v 1.3 1997/11/05 04:19:49 asami Exp
#

DISTNAME=	kdegames-1.1.2
CATEGORIES=	games kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/1.1.2/distribution/tar/generic/source/bz2/ \
		ftp://ftp.de.kde.org/pub/kde/stable/1.1.2/distribution/tar/generic/source/bz2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.kde.org/

DEPENDS+=	kdebase-1.1.2:../../x11/kdebase
DEPENDS+=	qwspritefield-1.6:../../x11/qwspritefield

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--datadir=${PREFIX}/share/kde" \
		"--with-qt-dir=${PREFIX}" \
		"--with-qt-includes=${PREFIX}/include/qt"
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib"

.include "../../mk/bsd.pkg.mk"
