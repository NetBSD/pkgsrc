# $NetBSD: Makefile,v 1.6 2000/07/10 15:08:18 agc Exp $
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
CONFIGURE_ENV+=	QTDIR=`${PKG_INFO} -qp qt1 | ${AWK} '{ print $$2 }'`/qt1
CONFIGURE_ENV+= MOC=`${PKG_INFO} -qp qt1 | ${AWK} '{ print $$2 }'`/qt1/bin/moc
CONFIGURE_ARGS+=--with-qt-dir=`${PKG_INFO} -qp qt1 | ${AWK} '{ print $$2 }'`/qt1

.include "../../mk/bsd.pkg.mk"
