# $NetBSD: Makefile,v 1.2 1999/12/13 19:24:02 hubertf Exp $
#

DISTNAME=	cervisia-0.3.1
CATEGORIES=	kde devel
MASTER_SITES=	ftp://linde.physik.hu-berlin.de/pub/bernd/cervisia/ \
		ftp://ftp.kde.org/pub/kde/unstable/apps/utils/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://pauli.uni-muenster.de/~gehrmab/cervisia/cervisia.html

DEPENDS+=	kdebase-1.1.2:../../x11/kdebase
DEPENDS+=	cvs-1.10:../../devel/cvs

USE_X11BASE=		yes	# To get this near KDE
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=--with-qt-includes=${X11BASE}/include/qt \
		--with-qt-libraries=${X11BASE}/lib \
		--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
