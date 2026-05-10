# $NetBSD: Makefile,v 1.9 2026/05/10 10:31:16 vins Exp $

DISTNAME=	bindfs-1.18.4
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	filesystems
MASTER_SITES=	https://bindfs.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bindfs.org/
COMMENT=	Remounts file system subtrees in arbitrary locations
LICENSE=	gnu-gpl-v2

USE_FEATURES=	getline

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	automake autoreconf gmake pkg-config
USE_LIBTOOL=	yes
USE_FUSE3=	yes

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
