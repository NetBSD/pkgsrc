# $NetBSD: Makefile,v 1.38 2002/09/01 04:26:10 hubertf Exp $
#

DISTNAME=	kdegraphics-1.1.2
PKGREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_LOCAL}/kde1
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.kde.org/
COMMENT=	Graphics programs for the KDE integrated X11 desktop

DEPENDS+=	kdebase-1.1.2nb1:../../x11/kdebase

USE_X11BASE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/admin/ltconfig \
			${WRKSRC}/kdvi/kpathsea/ltconfig

EVAL_PREFIX+=	QT1DIR=qt1 KDEBASEDIR=kdebase
CONFIGURE_ARGS=	"--datadir=${KDEBASEDIR}/share/kde" \
		"--with-qt-dir=${QT1DIR}/qt1"
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=  KDEDIR=${KDEBASEDIR} \
		CXXFLAGS="${CFLAGS}" \
		all_libraries="-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib -Wl,-R${X11BASE}/lib -L${X11BASE}/lib"

.include "../../mk/bsd.pkg.mk"
