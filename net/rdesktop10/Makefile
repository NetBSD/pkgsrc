# $NetBSD: Makefile,v 1.1.1.1 2002/08/23 03:12:25 grant Exp $
#

DISTNAME=		rdesktop-1.0.0-pl19-8-0
PKGNAME=		rdesktop-1.0.0.19.8.0
CATEGORIES=		net
MASTER_SITES=		http://bibl4.oru.se/projects/rdesktop/dist/tar/src/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		grant@netbsd.org
HOMEPAGE=		http://www.rdesktop.org/
COMMENT=		Open-source Remote Desktop Protocol client

USE_GMAKE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${LOCALBASE}
CONFIGURE_ARGS+=	--with-openssl

CFLAGS+=		-Icrypto
LDFLAGS+=		-lcrypto

USE_X11=		yes

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
