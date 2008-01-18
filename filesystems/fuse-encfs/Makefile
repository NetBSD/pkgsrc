# $NetBSD: Makefile,v 1.4 2008/01/18 05:06:33 tnn Exp $
#

DISTNAME=	encfs-1.2.0-2
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=encfs/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://arg0.net/wiki/encfs
COMMENT=	FUSE Encrypted Filesystem

WRKSRC=		${WRKDIR}/${DISTNAME:S/-2//}
GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf gmake pkg-config
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CPPFLAGS+=	-D_NETBSD_SOURCE
.endif

.include "../../devel/librlog/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
