# $NetBSD: Makefile,v 1.2 2020/11/24 15:03:22 ryoon Exp $

GITHUB_PROJECT=	exfat
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	fuse-exfat-1.3.0
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=relan/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/relan/exfat
COMMENT=	FUSE file-system and utilities for exFAT file systems
LICENSE=	gnu-gpl-v2


USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_TOOLS+=	autoheader automake autoreconf gmake pkg-config

post-extract:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
