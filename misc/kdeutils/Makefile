# $NetBSD: Makefile,v 1.53 2003/12/26 19:57:22 wiz Exp $
# FreeBSD Id: Makefile,v 1.4 1997/11/28 00:04:18 se Exp
#

DISTNAME=	kdeutils-1.1.2
PKGREVISION=	2
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_LOCAL}/kde1
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	Various utilities for the KDE integrated X11 desktop

DEPENDS+=	kdebase-1.1.2nb4:../../x11/kdebase

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

EVAL_PREFIX+=	QT1DIR=qt1 KDEBASEDIR=kdebase
CONFIGURE_ARGS=	"--with-qt-dir=${QT1DIR}/qt1"
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	KDEDIR=${KDEBASEDIR} \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="${KDE_LDFLAGS}"

FIX_RPATH+=	KDE_LDFLAGS
KDE_LDFLAGS=	-L${LOCALBASE}/lib -Wl,${RPATH_FLAG}${LOCALBASE}/lib -L${X11BASE}/lib -Wl,${RPATH_FLAG}${X11BASE}/lib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	DO_NOT_COMPILE=kab
.endif

.include "../../mk/bsd.pkg.mk"
