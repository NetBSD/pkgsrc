# $NetBSD: Makefile,v 1.16 2003/12/26 19:57:31 wiz Exp $

DISTNAME=		kicq-1.0.0
PKGREVISION=		2
CATEGORIES=		chat kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kicq/}

MAINTAINER=		magick@NetBSD.org
HOMEPAGE=		http://kicq.sourceforge.net/
COMMENT=		KDE ICQ client

DEPENDS+=		icqlib>=1.0.0:../../chat/icqlib
DEPENDS+=		kdebase-1.1.2nb4:../../x11/kdebase

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
			all_libraries="${KDE_LDFLAGS}"

FIX_RPATH+=	KDE_LDFLAGS
KDE_LDFLAGS=	-Wl,${RPATH_FLAG}${QT1DIR}/qt1/lib -L${LOCALBASE}/lib -Wl,${RPATH_FLAG}${LOCALBASE}/lib -L${X11BASE}/lib -Wl,${RPATH_FLAG}${X11BASE}/lib -ltiff -ljpeg -lpng -lz

.include "../../mk/bsd.pkg.mk"
