# $NetBSD: Makefile,v 1.1.1.1 1999/11/05 04:32:07 hubertf Exp $
#

DISTNAME=	cervisia-0.2.1
CATEGORIES=	kde devel
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/unstable/apps/utils/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://pauli.uni-muenster.de/~gehrmab/cervisia.html

DEPENDS+=	kdebase-1.1.2:../../x11/kdebase
DEPENDS+=	cvs-1.10:../../devel/cvs

USE_X11BASE=		yes	# To get this near KDE
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=--with-qt-includes=${X11BASE}/include/qt \
		--with-qt-libraries=${X11BASE}/lib \
		--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
