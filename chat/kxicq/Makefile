# $NetBSD: Makefile,v 1.3 2001/06/11 06:34:21 jlam Exp $

DISTNAME=		kxicq-03132000
CATEGORIES=		chat kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kxicq/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.kxicq.org/
COMMENT=		KDE ICQ client

DEPENDS+=		esound>=0.2.7:../../audio/esound
DEPENDS+=		kdebase-1.1.2:../../x11/kdebase

USE_X11BASE=		yes
USE_GMAKE=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

EVAL_PREFIX+=		QT1DIR=qt1 KDEBASEDIR=kdebase
CONFIGURE_ARGS+=	--datadir=${KDEBASEDIR}/share/kde \
			--with-qt-dir=${QT1DIR}/qt1
CONFIGURE_ENV+=		KDEDIR=${KDEBASEDIR} \
			CXXFLAGS="${CFLAGS}" \
			all_libraries="-Wl,-R${QT1DIR}/qt1/lib -L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -L${X11BASE}/lib -Wl,-R${X11BASE}/lib -ltiff -ljpeg -lpng -lz"

post-extract:
	@${RM} -fr ${WRKSRC}/kxicq/ltdl

.include "../../mk/bsd.pkg.mk"
