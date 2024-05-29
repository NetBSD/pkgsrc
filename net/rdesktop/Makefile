# $NetBSD: Makefile,v 1.68 2024/05/29 16:34:02 adam Exp $

DISTNAME=		rdesktop-1.9.0
PKGREVISION=		16
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=rdesktop/}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.rdesktop.org/
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

CONFIGURE_ARGS.NetBSD+=	--with-sound=oss

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-sound=alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
