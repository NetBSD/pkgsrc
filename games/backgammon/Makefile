# $NetBSD: Makefile,v 1.10 2003/08/01 17:26:38 wiz Exp $
#

DISTNAME=	bacKgammon-1.9.1b
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=backgammon/}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://bacKgammon.sourceforge.net/
COMMENT=	KDE frontend for first internet backgammon server (FIBS)

DEPENDS+=	kde-1.1.2nb3:../../x11/kde

GNU_CONFIGURE=	yes
EVAL_PREFIX+=   QT1DIR=qt1 KDEBASEDIR=kdebase
USE_X11BASE=	yes
CONFIGURE_ARGS+=--datadir=${KDEBASEDIR}/share/kde \
		--with-qt-dir=${QT1DIR}/qt1 \
		--with-qt-libraries='${QT1DIR}/qt1/lib -L${LOCALBASE}/lib' \
		--enable-path-check
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=  KDEDIR=${KDEBASEDIR} \
		MOC=${QT1DIR}/qt1/bin/moc \
		QTDIR=${QT1DIR}/qt1 \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="${KDE_LDFLAGS}"

FIX_RPATH+=	KDE_LDFLAGS
KDE_LDFLAGS=	-L${LOCALBASE}/lib -Wl,${RPATH_FLAG}${LOCALBASE}/lib -L${X11BASE}/lib -Wl,${RPATH_FLAG}${X11BASE}/lib

.include "../../mk/bsd.pkg.mk"
