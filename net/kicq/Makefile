# $NetBSD: Makefile,v 1.3 2000/11/11 17:49:27 tron Exp $

DISTNAME=		kicq-1.0.0
CATEGORIES=		net kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kicq/}

MAINTAINER=		magick@bundy.lip.owl.de
HOMEPAGE=		http://kicq.sourceforge.net/

BUILD_DEPENDS+=		${LOCALBASE}/bin/autoconf:../../devel/autoconf
DEPENDS+=		icqlib>=1.0.0:../../net/icqlib
DEPENDS+=		kdebase-1.1.2:../../x11/kdebase

USE_X11BASE=		yes
USE_GMAKE=		yes
LTCONFIG_OVERRIDE=      ${WRKSRC}/ltconfig
USE_LIBTOOL=            yes
GNU_CONFIGURE=		yes

EVAL_PREFIX+=		QT1DIR=qt1 KDEBASEDIR=kdebase
CONFIGURE_ARGS+=	--datadir=${KDEBASEDIR}/share/kde \
			--with-qt-dir=${QT1DIR}/qt1 \
			--with-icq-includes=${LOCALBASE}/include \
			--with-icq-libs=${LOCALBASE}/lib
CONFIGURE_ENV+=		KDEDIR=${KDEBASEDIR} \
			CPPFLAGS="${CPPFLAGS}" \
			CXXFLAGS="${CFLAGS}" \
			all_libraries="-Wl,-R${QT1DIR}/qt1/lib -L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -L${X11BASE}/lib -Wl,-R${X11BASE}/lib -ltiff -ljpeg -lpng -lz"

.include "../../mk/bsd.pkg.mk"
