# $NetBSD: Makefile,v 1.1 2019/04/05 19:32:55 maya Exp $

GITHUB_PROJECT=	exfat
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	fuse-exfat-1.3.0
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=relan/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://alperakcan.net/projects/fuse-ext2/
COMMENT=	FUSE file-system and utilities for exFAT file systems
LICENSE=	gnu-gpl-v2


USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_TOOLS+=	autoheader automake autoreconf gmake pkg-config

post-extract:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
