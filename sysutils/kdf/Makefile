# $NetBSD: Makefile,v 1.1.1.1 1999/07/03 23:27:47 hubertf Exp $
#

DISTNAME=	kdf-0.5.1
CATEGORIES=	sysutils kde
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/1.1.1/apps/utils/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.edu.uni-klu.ac.at/~mkropfbe

DEPENDS+=	gettext-0.10.35:../../devel/gettext
DEPENDS+=	kde-1.1.1:../../x11/kde

USE_X11BASE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--datadir=${X11BASE}/share/kde \
		--with-qt-dir=${X11BASE} \
		--with-qt-includes=${X11BASE}/include/qt \
		--enable-path-check
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	KDEDIR=${PREFIX} \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib"

.include "../../mk/bsd.pkg.mk"
