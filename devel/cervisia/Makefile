# $NetBSD: Makefile,v 1.11 2000/11/11 17:49:24 tron Exp $
#

DISTNAME=	cervisia-0.7.2
CATEGORIES=	kde devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cervisia/} \
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
