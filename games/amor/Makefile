# $NetBSD: Makefile,v 1.8 2000/07/15 20:39:17 agc Exp $
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

EVAL_PREFIX+=	QT1DIR=qt1
CONFIGURE_ENV+=	QTDIR=${QT1DIR}/qt1
CONFIGURE_ARGS+=--with-qt-dir=${QT1DIR}/qt1

.include "../../mk/bsd.pkg.mk"
