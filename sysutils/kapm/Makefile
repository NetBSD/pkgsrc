# $NetBSD: Makefile,v 1.20 2003/12/26 19:55:55 wiz Exp $
#

DISTNAME=	kapm-0.3.1
PKGREVISION=	2
CATEGORIES=	sysutils x11 kde
MASTER_SITES=	ftp://bodnar42.dhs.org/pub/kapm/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://bodnar42.dhs.org/kapm/
COMMENT=	Monitor a laptop's battery status and perform other APM tasks

.if !exists(/usr/include/machine/apmvar.h)
PKG_SKIP_REASON=	"APM is not available for ${MACHINE_PLATFORM}"
.endif

DEPENDS+=	kdebase-1.1.2nb4:../../x11/kdebase

USE_X11BASE=	YES	# to get things near KDE
GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

EVAL_PREFIX+=	QT1DIR=qt1
CONFIGURE_ENV+=	QTDIR=${QT1DIR}/qt1
CONFIGURE_ENV+= MOC=${QT1DIR}/qt1/bin/moc
CONFIGURE_ARGS+=--with-qt-dir=${QT1DIR}/qt1

.include "../../mk/bsd.pkg.mk"
