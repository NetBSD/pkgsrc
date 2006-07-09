# $NetBSD: Makefile,v 1.11 2006/07/09 09:27:52 xtraeme Exp $
#

DISTNAME=	openobex-1.3
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openobex/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://openobex.sourceforge.net/
COMMENT=	Implementation of the Object Exchange (OBEX) protocol

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf gmake pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE=	openobex-config.in

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD" && exists(/usr/include/bluetooth.h))
SUBST_CLASSES+=		bt
SUBST_STAGE.bt=		post-patch
SUBST_FILES.bt=		include/obex.h
SUBST_SED.bt=		-e "s|ifndef SOL_RFCOMM|ifdef SOL_RFCOMM|"
SUBST_MESSAGE.bt=	Fixing bluetooth detection.
.endif

post-patch:
	cd ${WRKSRC} && autoconf

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
