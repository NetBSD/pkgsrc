# $NetBSD: Makefile,v 1.8 2006/07/02 18:16:53 xtraeme Exp $
#

DISTNAME=	openobex-1.0.1
PKGREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openobex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openobex.sourceforge.net/
COMMENT=	Implementation of the Object Exchange (OBEX) protocol

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
USE_LIBTOOL=	YES

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD" && exists(/usr/include/bluetooth.h))
SUBST_CLASSES+=		bt
SUBST_STAGE.bt=		post-patch
SUBST_FILES.bt=		configure
SUBST_SED.bt=		-e "s|bluetooth/bluetooth.h|bluetooth.h|g"
SUBST_SED.bt+=		-e "s|bluetooth/rfcomm.h|netbt/rfcomm.h|g"
SUBST_SED.bt+=		-e "s|sockaddr_rc|sockaddr_bt|g"
SUBST_MESSAGE.bt=	Fixing bluetooth detection.

# bacpy() and friends
CPPFLAGS+=		-DCOMPAT_BLUEZ
.endif

.include "../../mk/bsd.pkg.mk"
