# $NetBSD: Makefile,v 1.8 2000/07/14 16:04:26 agc Exp $
#

DISTNAME=	kapm-0.3.1
CATEGORIES=	sysutils x11 kde
MASTER_SITES=	ftp://bodnar42.dhs.org/pub/kapm/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://bodnar42.dhs.org/kapm/

.if !exists(/usr/include/machine/apmvar.h)
IGNORE+=	"APM is not available for ${MACHINE_PLATFORM}"
.endif

DEPENDS+=	kdebase-1.1.2:../../x11/kdebase

USE_X11BASE=	YES	# to get things near KDE
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	QTDIR=`${SHOW_PREFIX1} qt1 ${SHOW_PREFIX2}`/qt1
CONFIGURE_ENV+= MOC=`${SHOW_PREFIX1} qt1 ${SHOW_PREFIX2}`/qt1/bin/moc
CONFIGURE_ARGS+=--with-qt-dir=`${SHOW_PREFIX1} qt1 ${SHOW_PREFIX2}`/qt1

.include "../../mk/bsd.pkg.mk"
