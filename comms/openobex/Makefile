# $NetBSD: Makefile,v 1.10 2006/07/06 16:31:39 rillig Exp $
#

DISTNAME=	openobex-1.0.1
PKGREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openobex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openobex.sourceforge.net/
COMMENT=	Implementation of the Object Exchange (OBEX) protocol

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE=	openobex-config.in

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD" && exists(/usr/include/bluetooth.h))
SUBST_CLASSES+=		bt
SUBST_STAGE.bt=		post-patch
SUBST_FILES.bt=		configure
SUBST_SED.bt=		-e "s|bluetooth/bluetooth.h|bluetooth.h|g"
SUBST_SED.bt+=		-e "s|bluetooth/rfcomm.h|netbt/rfcomm.h|g"
SUBST_SED.bt+=		-e "s|sockaddr_rc|sockaddr_bt|g"
SUBST_MESSAGE.bt=	Fixing bluetooth detection.

SUBST_CLASSES+=		bt2
SUBST_STAGE.bt2=	post-patch
SUBST_FILES.bt2=	src/obex.h
SUBST_SED.bt2=		-e "s|ifndef SOL_RFCOMM|ifdef SOL_RFCOMM|"

# bacpy() and friends
CPPFLAGS+=		-DCOMPAT_BLUEZ
.endif

.include "../../mk/bsd.pkg.mk"
