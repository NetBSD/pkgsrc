# $NetBSD: Makefile,v 1.8 2001/11/06 11:57:19 tron Exp $

DISTNAME=		kicq-1.0.0
CATEGORIES=		chat kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kicq/}

MAINTAINER=		magick@netbsd.org
HOMEPAGE=		http://kicq.sourceforge.net/
COMMENT=		KDE ICQ client

BUILD_DEPENDS+=		autoconf>=2.13:../../devel/autoconf
DEPENDS+=		icqlib>=1.0.0:../../chat/icqlib
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
			CXXFLAGS="${CFLAGS}" \
			all_libraries="-Wl,-R${QT1DIR}/qt1/lib -L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -L${X11BASE}/lib -Wl,-R${X11BASE}/lib -ltiff -ljpeg -lpng -lz"

.include "../../mk/bsd.pkg.mk"
