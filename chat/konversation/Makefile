# $NetBSD: Makefile,v 1.8 2006/12/07 11:08:26 markd Exp $
#

DISTNAME=	konversation-1.0.1
PKGREVISION=	1
CATEGORIES=	chat kde
MASTER_SITES=	http://download.berlios.de/konversation/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://konversation.kde.org/
COMMENT=	KDE IRC Client

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake perl msgfmt
USE_LANGUAGES=	c c++

REPLACE_PERL+=		konversation/src/konversation-0.19-appearance.pl \
			konversation/src/konversation-0.19-colorcodes.pl \
			konversation/src/konversation-0.19-colors.pl \
			konversation/src/konversation-0.19-custombrowser.pl \
			konversation/src/konversation-0.19-notifylists.pl \
			konversation/src/konversation-0.19-sortorder.pl \
			konversation/src/konversation-0.19-tabplacement.pl \
			konversation/src/konversation-0.20-customfonts.pl \
			konversation/src/konversation-0.20-quickbuttons.pl
REPLACE_BASH+=		konversation/scripts/mail
USE_TOOLS+=		bash:run

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--disable-threading
.endif

.include "../../mk/bsd.pkg.mk"
