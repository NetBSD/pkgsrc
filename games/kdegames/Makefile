# $NetBSD: Makefile,v 1.52 2003/12/26 19:56:12 wiz Exp $
# FreeBSD Id: Makefile,v 1.3 1997/11/05 04:19:49 asami Exp
#

DISTNAME=	kdegames-1.1.2
PKGREVISION=	2
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_LOCAL}/kde1
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	Games for the KDE integrated X11 desktop

DEPENDS+=	kdebase-1.1.2nb4:../../x11/kdebase
DEPENDS+=	qwspritefield-1.6:../../x11/qwspritefield

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

EVAL_PREFIX+=	QT1DIR=qt1 KDEBASEDIR=kdebase
CONFIGURE_ARGS=	"--datadir=${KDEBASEDIR}/share/kde" \
		"--with-qt-dir=${QT1DIR}/qt1"
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	KDEDIR=${KDEBASEDIR} \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="${KDE_LDFLAGS}"

FIX_RPATH+=	KDE_LDFLAGS
KDE_LDFLAGS=	-L${LOCALBASE}/lib -Wl,${RPATH_FLAG}${LOCALBASE}/lib -L${X11BASE}/lib -Wl,${RPATH_FLAG}${X11BASE}/lib

.include "../../mk/bsd.pkg.mk"
