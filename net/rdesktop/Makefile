# $NetBSD: Makefile,v 1.20 2005/02/15 20:20:06 xtraeme Exp $
#

DISTNAME=		rdesktop-1.3.1
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rdesktop/}

PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCHFILES=		rdesktop.patch
PATCH_DIST_STRIP=	-p0

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.rdesktop.org/
COMMENT=		Open-source Remote Desktop Protocol client

USE_BUILDLINK3=		YES
USE_X11=		YES
HAS_CONFIGURE=		YES
CONFIGURE_ARGS=		--prefix=${PREFIX}
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
