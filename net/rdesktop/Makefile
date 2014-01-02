# $NetBSD: Makefile,v 1.42 2014/01/02 15:12:16 prlw1 Exp $

DISTNAME=		rdesktop-1.8.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rdesktop/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.rdesktop.org/
COMMENT=		Open-source Remote Desktop Protocol client
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		YES
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--with-x=${X11BASE}
CONFIGURE_ARGS+=	--disable-credssp
CONFIGURE_ARGS+=	--disable-smartcard

LDFLAGS+=		${LIBOSSAUDIO}

SUBST_CLASSES+=		audio
SUBST_STAGE.audio=	pre-configure
SUBST_FILES.audio=	rdpsnd_oss.c
SUBST_SED.audio=	-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.audio=	Fixing hardcoded audio device.

.include "options.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-sound=oss
.endif

.include "../../mk/oss.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
