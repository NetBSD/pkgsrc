# $NetBSD: Makefile,v 1.5 2000/07/10 15:08:15 agc Exp $
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
CONFIGURE_ENV+=	"QTDIR=`${PKG_INFO} -qp qt1 | ${AWK} '{ print $$2 }'`/qt1"
CONFIGURE_ARGS+=--with-qt-includes=`${PKG_INFO} -qp qt1 | ${AWK} '{ print $$2 }'`/qt1/include \
		--with-qt-libraries=`${PKG_INFO} -qp qt1 | ${AWK} '{ print $$2 }'`/qt1/lib \
		--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
