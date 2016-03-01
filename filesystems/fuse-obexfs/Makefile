# $NetBSD: Makefile,v 1.8 2016/03/01 20:16:33 joerg Exp $
#

DISTNAME=	obexfs-0.8
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openobex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openobex.org/
COMMENT=	FUSE based filesystem using ObexFTP
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf gmake pkg-config

CPPFLAGS.NetBSD+=	-D_KERNTYPES

BUILDLINK_API_DEPENDS.openobex+=	openobex>=1.3nb2

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../comms/obexftp/buildlink3.mk"
.include "../../comms/openobex/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
