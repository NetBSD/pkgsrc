# $NetBSD: Makefile,v 1.3 2000/02/24 02:12:35 hubertf Exp $
#

DISTNAME=	cervisia-0.5.0
CATEGORIES=	kde devel
MASTER_SITES=	ftp://linde.physik.hu-berlin.de/pub/bernd/cervisia/ \
		ftp://ftp.kde.org/pub/kde/unstable/apps/utils/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://cervisia.sourceforge.net/

DEPENDS+=	kde-1.1.2:../../x11/kde
DEPENDS+=	cvs-1.10:../../devel/cvs

USE_X11BASE=		yes	# To get this near KDE
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=--with-qt-includes=${X11BASE}/include/qt \
		--with-qt-libraries=${X11BASE}/lib \
		--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
