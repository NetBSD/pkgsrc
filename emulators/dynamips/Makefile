# $NetBSD: Makefile,v 1.16 2026/07/17 16:42:13 wiz Exp $

DISTNAME=	dynamips-0.2.24
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=GNS3/}
GITHUB_PROJECT=	dynamips
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	https://github.com/GNS3/dynamips
COMMENT=	Cisco 3600 and 7200 MIPS emulator
LICENSE=	gnu-gpl-v2

SUBST_CLASSES+=		libelf
SUBST_STAGE.libelf=	pre-configure
SUBST_FILES.libelf=	common/dynamips.h common/rom2c.c
SUBST_SED.libelf=	-e 's,<libelf.h>,<libelf/libelf.h>,'
SUBST_MESSAGE.libelf=	Fix libelf header file path

.include "../../devel/cmake/build.mk"
.include "../../devel/libelf/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
