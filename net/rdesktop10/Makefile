# $NetBSD: Makefile,v 1.4 2003/11/12 03:39:42 jschauma Exp $
#

DISTNAME=		rdesktop-1.0.0-pl19-8-0
PKGNAME=		rdesktop-1.0.0.19.8.0
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://bibl4.oru.se/projects/rdesktop/dist/tar/src/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		grant@NetBSD.org
HOMEPAGE=		http://www.rdesktop.org/
COMMENT=		Open-source Remote Desktop Protocol client

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_X11=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${LOCALBASE}
CONFIGURE_ARGS+=	--with-openssl

CFLAGS+=		-Icrypto
LDFLAGS+=		-lcrypto

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
