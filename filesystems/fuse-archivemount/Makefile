# $NetBSD: Makefile,v 1.10 2021/11/30 17:13:14 pho Exp $
#

DISTNAME=	archivemount-0.9.1
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	filesystems
MASTER_SITES=	http://www.cybernoia.de/software/archivemount/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cybernoia.de/software/archivemount/
COMMENT=	FUSE gateway to libarchive
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config automake autoreconf
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
