# $NetBSD: Makefile,v 1.6 2012/10/03 16:08:32 asau Exp $
#

DISTNAME=	obexfs-0.8
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openobex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openobex.org/
COMMENT=	FUSE based filesystem using ObexFTP

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf gmake pkg-config

BUILDLINK_API_DEPENDS.openobex+=	openobex>=1.3nb2

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../comms/obexftp/buildlink3.mk"
.include "../../comms/openobex/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
