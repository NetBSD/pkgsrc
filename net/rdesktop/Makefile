# $NetBSD: Makefile,v 1.15 2004/01/24 14:01:47 xtraeme Exp $
#

DISTNAME=		rdesktop-1.3.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rdesktop/}

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.rdesktop.org/
COMMENT=		Open-source Remote Desktop Protocol client

USE_BUILDLINK2=		YES
USE_X11=		YES
HAS_CONFIGURE=		YES
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-x=${X11BASE}
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}

CFLAGS+=		-DAUDIO_DEV=\"\\\"${DEVOSSAUDIO}\\\"\"
LDFLAGS+=		${LIBOSSAUDIO}

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
