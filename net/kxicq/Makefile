# $NetBSD: Makefile,v 1.3 2000/07/11 14:53:44 agc Exp $

DISTNAME=		kxicq-03132000
CATEGORIES=		net kde
MASTER_SITES=		http://download.sourceforge.net/kxicq/

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.kxicq.org/

DEPENDS+=		esound>=0.2.7:../../audio/esound
DEPENDS+=		kdebase-1.1.2:../../x11/kdebase

USE_X11BASE=		yes
USE_GMAKE=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/kde \
			--with-qt-dir=`${MAKE} show-qt1-prefix`/qt1
CONFIGURE_ENV+=		KDEDIR=${PREFIX} \
			CPPFLAGS="${CPPFLAGS}" \
			CXXFLAGS="${CFLAGS}" \
			all_libraries="-Wl,-R`${MAKE} show-qt1-prefix`/qt1/lib -L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -L${X11BASE}/lib -Wl,-R${X11BASE}/lib -ltiff -ljpeg -lpng -lz"

post-extract:
	@${RM} -fr ${WRKSRC}/kxicq/ltdl

.include "../../mk/bsd.pkg.mk"
