# $NetBSD: Makefile,v 1.21 2005/03/23 15:24:11 xtraeme Exp $
#

DISTNAME=		rdesktop-1.4.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rdesktop/}

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.rdesktop.org/
COMMENT=		Open-source Remote Desktop Protocol client

USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-x=${X11BASE}
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}

LDFLAGS+=		${LIBOSSAUDIO}

SUBST_CLASSES+=		audio
SUBST_STAGE.audio=	pre-configure
SUBST_FILES.audio=	rdpsnd_oss.c
SUBST_SED.audio=	-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.audio=	"Fixing hardcoded audio device."

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
