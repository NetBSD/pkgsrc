# $NetBSD: Makefile,v 1.7 2000/07/14 16:04:21 agc Exp $
#

DISTNAME=	amor-0.6
CATEGORIES=	games kde
MASTER_SITES=	http://www.powerup.com.au/~mjones/amor/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.powerup.com.au/~mjones/amor/index.html

DEPENDS+=	kdebase-1.1.2:../../x11/kdebase

USE_X11BASE=		yes	# To get this near KDE
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=	QTDIR=`${SHOW_PREFIX1} qt1 ${SHOW_PREFIX2}`/qt1
CONFIGURE_ARGS+=--with-qt-dir=`${SHOW_PREFIX1} qt1 ${SHOW_PREFIX2}`/qt1

.include "../../mk/bsd.pkg.mk"
