# $NetBSD: Makefile,v 1.15 2002/11/04 23:27:18 wiz Exp $
#

DISTNAME=	cervisia-1.0
PKGREVISION=	1
CATEGORIES=	kde devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cervisia/} \
		ftp://ftp.kde.org/pub/kde/unstable/apps/utils/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://cervisia.sourceforge.net/
COMMENT=	Graphical frontend for the CVS client

DEPENDS+=	kde-1.1.2nb2:../../x11/kde
DEPENDS+=	cvs>=1.10:../../devel/cvs

USE_X11BASE=		yes	# To get this near KDE
GNU_CONFIGURE=		yes

EVAL_PREFIX+=	QT1DIR=qt1
CONFIGURE_ENV+=	"QTDIR=${QT1DIR}/qt1"
CONFIGURE_ARGS+=--with-qt-includes=${QT1DIR}/qt1/include \
		--with-qt-libraries=${QT1DIR}/qt1/lib \
		--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib \
		--with-kde-version=1

.include "../../mk/bsd.pkg.mk"
