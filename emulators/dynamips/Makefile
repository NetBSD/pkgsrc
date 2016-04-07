# $NetBSD: Makefile,v 1.11 2016/04/07 14:24:51 ryoon Exp $

DISTNAME=	dynamips-0.2.16
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=GNS3/}
GITHUB_PROJECT=	dynamips
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	https://github.com/GNS3/dynamips
COMMENT=	Cisco 3600 and 7200 MIPS emulator
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
USE_CMAKE=	yes

SUBST_CLASSES+=		libelf
SUBST_STAGE.libelf=	post-patch
SUBST_FILES.libelf=	common/dynamips.h common/rom2c.c
SUBST_SED.libelf=	-e 's,<libelf.h>,<libelf/libelf.h>,'
SUBST_MESSAGE.libelf=	Fix libelf header file path

.include "../../devel/libelf/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
