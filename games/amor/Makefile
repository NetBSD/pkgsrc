# $NetBSD: Makefile,v 1.2 1999/11/05 02:29:28 hubertf Exp $
#

DISTNAME=	amor-0.6
CATEGORIES=	games kde
MASTER_SITES=	http://www.powerup.com.au/~mjones/amor/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.powerup.com.au/~mjones/amor/index.html

DEPENDS+=	kdebase-1.1.2:../../x11/kdebase
DEPENDS+=	nmap-2.12:../../net/nmap

USE_X11BASE=		yes	# To get this near KDE
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=--with-qt-includes=${X11BASE}/include/qt \
		--with-qt-libraries=${X11BASE}/lib

.include "../../mk/bsd.pkg.mk"
