# $NetBSD: Makefile,v 1.1.1.1 1999/11/02 21:54:47 hubertf Exp $
#

DISTNAME=	kapm-0.3.1
CATEGORIES=	sysutils x11 kde
MASTER_SITES=	ftp://bodnar42.dhs.org/pub/kapm/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://bodnar42.dhs.org/kapm/

USE_X11BASE=	YES	# to get things near KDE
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-qt-includes=${X11BASE}/include/qt \
		--with-qt-libraries=${X11BASE}/lib

.include "../../mk/bsd.pkg.mk"
