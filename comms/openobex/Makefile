# $NetBSD: Makefile,v 1.17 2009/03/20 19:42:20 hasso Exp $
#

DISTNAME=	openobex-1.3
PKGREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openobex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openobex.triq.net/
COMMENT=	Implementation of the Object Exchange (OBEX) protocol

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf gmake pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE=	openobex.pc.in

.include "../../mk/bsd.prefs.mk"

.if ((${OPSYS} == "NetBSD" && exists(/usr/include/bluetooth.h)) || ${OPSYS} == "DragonFly")
SUBST_CLASSES+=		bt
SUBST_STAGE.bt=		post-patch
SUBST_FILES.bt=		include/obex.h
SUBST_SED.bt=		-e "s,\#ifndef SOL_RFCOMM,\#if defined(__NetBSD__) || defined(__DragonFly__),"
SUBST_SED.bt+=		-e "s,typedef char\* bdaddr_t\;,\#include \<bluetooth.h\>,"
SUBST_MESSAGE.bt=	Fixing bluetooth detection.
.endif

post-patch:
	cd ${WRKSRC} && autoconf

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
