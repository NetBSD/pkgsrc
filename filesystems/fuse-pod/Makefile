# $NetBSD: Makefile,v 1.44 2022/01/22 18:45:13 pho Exp $
#

DISTNAME=	fusepod-0.5.1
PKGNAME=	fuse-pod-0.5.1
PKGREVISION=	38
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fusepod/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fusepod.sourceforge.net/
COMMENT=	FUSE-based filesystem for iPod
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++03
USE_TOOLS+=	gmake pkg-config

.include "../../audio/libgpod/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
