# $NetBSD: Makefile,v 1.3 2000/04/12 22:35:18 dmcmahill Exp $

DISTNAME=	kdetoys-1.1.2
CATEGORIES=	games kde
MASTER_SITES=	ftp://ftp.us.kde.org/pub/kde/stable/1.1.2/distribution/tar/generic/source/bz2/ \
		ftp://ftp.de.kde.org/pub/kde/stable/1.1.2/distribution/tar/generic/source/bz2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.kde.org/

DEPENDS+=	kdebase-1.1.2:../../x11/kdebase

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--datadir=${PREFIX}/share/kde" \
		"--with-qt-dir=${X11BASE}/qt1"
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		QTDIR=${X11BASE}/qt1 \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-L${X11BASE}/lib -Wl,-R${X11BASE}/lib -L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib"

.include "../../mk/bsd.pkg.mk"
