# $NetBSD: Makefile,v 1.5 2006/09/15 09:50:39 he Exp $
#

DISTNAME=	konversation-1.0
CATEGORIES=	chat
MASTER_SITES=	http://download.berlios.de/konversation/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://konversation.kde.org/
COMMENT=	KDE IRC Client

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake perl msgfmt
USE_LANGUAGES=	c c++
LANGS=		da en es et st it nl pt ru sv

USE_PKGLOCALEDIR=	YES
CONFIGURE_ENV+=		kde_htmldir=${PREFIX}/share/doc/kde/HTML
REPLACE_PERL+=		konversation/src/konversation-0.19-appearance.pl \
			konversation/src/konversation-0.19-colorcodes.pl \
			konversation/src/konversation-0.19-colors.pl \
			konversation/src/konversation-0.19-custombrowser.pl \
			konversation/src/konversation-0.19-notifylists.pl \
			konversation/src/konversation-0.19-sortorder.pl \
			konversation/src/konversation-0.19-tabplacement.pl \
			konversation/src/konversation-0.20-customfonts.pl \
			konversation/src/konversation-0.20-quickbuttons.pl

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--disable-threading
.endif

CONFIGURE_ARGS+=	--with-extra-includes=${BUILDLINK_PREFIX.jpeg}/include
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/kde

BUILDLINK_API_DEPENDS.kdelibs+=	kdelibs>=3.4.0

post-install:
.for f in ${LANGS}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/kde/HTML/${f}/common
.endfor

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
