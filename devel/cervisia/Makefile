# $NetBSD: Makefile,v 1.10 2000/11/05 16:52:13 hubertf Exp $
#

DISTNAME=	cervisia-0.7.2
CATEGORIES=	kde devel
MASTER_SITES=	http://download.sourceforge.net/cervisia/ \
		ftp://ftp.sourceforge.net/pub/cervisia/ \
		ftp://ftp.kde.org/pub/kde/unstable/apps/utils/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://cervisia.sourceforge.net/

DEPENDS+=	kde-1.1.2:../../x11/kde
DEPENDS+=	cvs>=1.10:../../devel/cvs

USE_X11BASE=		yes	# To get this near KDE
GNU_CONFIGURE=		yes

EVAL_PREFIX+=	QT1DIR=qt1
CONFIGURE_ENV+=	"QTDIR=${QT1DIR}/qt1"
CONFIGURE_ARGS+=--with-qt-includes=${QT1DIR}/qt1/include \
		--with-qt-libraries=${QT1DIR}/qt1/lib \
		--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
