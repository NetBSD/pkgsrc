# $NetBSD: Makefile,v 1.10 2022/01/22 18:43:19 pho Exp $
#

DISTNAME=	obexfs-0.8
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openobex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.openobex.org/
COMMENT=	FUSE based filesystem using ObexFTP
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf gmake pkg-config

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../comms/obexftp/buildlink3.mk"
.include "../../comms/openobex/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
