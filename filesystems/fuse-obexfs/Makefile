# $NetBSD: Makefile,v 1.1.1.1 2007/05/16 10:32:52 xtraeme Exp $
#

DISTNAME=	obexfs-0.8
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openobex/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.openobex.org/
COMMENT=	FUSE based filesystem using ObexFTP

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf gmake pkg-config

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../mk/bsd.prefs.mk"

# puffs does not play well with libpthread, disable it.
.if ${OPSYS} == "NetBSD"
BUILDLINK_TRANSFORM+=	rm:-lpthread
.endif

.include "../../comms/obexftp/buildlink3.mk"
.include "../../comms/openobex/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
