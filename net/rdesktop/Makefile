# $NetBSD: Makefile,v 1.16 2004/03/06 12:26:53 xtraeme Exp $
#

DISTNAME=		rdesktop-1.3.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rdesktop/}

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.rdesktop.org/
COMMENT=		Open-source Remote Desktop Protocol client

USE_BUILDLINK3=		YES
USE_X11=		YES
HAS_CONFIGURE=		YES
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-x=${X11BASE}
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE}

CFLAGS+=		-DAUDIO_DEV=\"\\\"${DEVOSSAUDIO}\\\"\"
LDFLAGS+=		${LIBOSSAUDIO}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
