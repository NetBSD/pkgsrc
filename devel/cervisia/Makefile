# $NetBSD: Makefile,v 1.7 2000/07/14 16:04:20 agc Exp $
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
CONFIGURE_ENV+=	"QTDIR=`${SHOW_PREFIX1} qt1 ${SHOW_PREFIX2}`/qt1"
CONFIGURE_ARGS+=--with-qt-includes=`${SHOW_PREFIX1} qt1 ${SHOW_PREFIX2}`/qt1/include \
		--with-qt-libraries=`${SHOW_PREFIX1} qt1 ${SHOW_PREFIX2}`/qt1/lib \
		--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
