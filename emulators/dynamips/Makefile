# $NetBSD: Makefile,v 1.1.1.1 2008/02/14 11:00:13 kefren Exp $

DISTNAME=	dynamips-0.2.7
CATEGORIES=	emulators
MASTER_SITES=	http://www.ipflow.utc.fr/dynamips/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.ipflow.utc.fr/index.php/Cisco_7200_Simulator
COMMENT=	Cisco 3600 and 7200 MIPS emulator

USE_TOOLS+=	gmake

NO_CONFIGURE=	yes

BUILD_TARGET=	# empty

SUBST_CLASSES+=		libelf
SUBST_STAGE.libelf=	post-patch
SUBST_FILES.libelf=	dynamips.h rom2c.c
SUBST_SED.libelf=	-e 's,<libelf.h>,<libelf/libelf.h>,'
SUBST_MESSAGE.libelf=	Fix libelf header file path

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dynamips ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nvram_export ${PREFIX}/bin

.include "../../devel/libelf/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
