# $NetBSD: Makefile,v 1.4 2000/06/26 16:44:21 dmcmahill Exp $
#

DISTNAME=	kapm-0.3.1
CATEGORIES=	sysutils x11 kde
MASTER_SITES=	ftp://bodnar42.dhs.org/pub/kapm/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://bodnar42.dhs.org/kapm/

.if !exists(/usr/include/machine/apmvar.h")
IGNORE+=	"APM is not available for ${MACHINE_PLATFORM}"
.endif

DEPENDS+=	kdebase-1.1.2:../../x11/kdebase

USE_X11BASE=	YES	# to get things near KDE
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	QTDIR=${X11BASE}/qt1 MOC=${X11BASE}/qt1/bin/moc
CONFIGURE_ARGS+=--with-qt-dir=${X11BASE}/qt1

.include "../../mk/bsd.pkg.mk"
