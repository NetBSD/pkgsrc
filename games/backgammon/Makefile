# $NetBSD: Makefile,v 1.7 2002/11/04 23:27:19 wiz Exp $
#

DISTNAME=	bacKgammon-1.9.1b
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=backgammon/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://bacKgammon.sourceforge.net/
COMMENT=	KDE frontend for first internet backgammon server (FIBS)

DEPENDS+=	kde-1.1.2nb2:../../x11/kde

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
		all_libraries="-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -L${X11BASE}/lib -Wl,-R${X11BASE}/lib"

.include "../../mk/bsd.pkg.mk"
