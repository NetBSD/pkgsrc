# $NetBSD: Makefile,v 1.14 2003/12/26 19:55:34 wiz Exp $
#

DISTNAME=	amor-0.6
PKGREVISION=	1
CATEGORIES=	games kde
MASTER_SITES=	http://www.powerup.com.au/~mjones/amor/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.powerup.com.au/~mjones/amor/index.html
COMMENT=	Small blob that sits on top of your active window

DEPENDS+=	kdebase-1.1.2nb4:../../x11/kdebase

USE_X11BASE=		yes	# To get this near KDE
GNU_CONFIGURE=		yes

EVAL_PREFIX+=	QT1DIR=qt1
CONFIGURE_ENV+=	QTDIR=${QT1DIR}/qt1
CONFIGURE_ARGS+=--with-qt-dir=${QT1DIR}/qt1

.include "../../mk/bsd.pkg.mk"
