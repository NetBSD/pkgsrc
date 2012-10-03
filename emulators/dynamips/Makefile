# $NetBSD: Makefile,v 1.7 2012/10/03 12:55:11 asau Exp $

DISTNAME=	dynamips-0.2.8-RC2
PKGNAME=	${DISTNAME:S/-RC/rc/}
CATEGORIES=	emulators
MASTER_SITES=	http://www.ipflow.utc.fr/dynamips/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.ipflow.utc.fr/index.php/Cisco_7200_Simulator
COMMENT=	Cisco 3600 and 7200 MIPS emulator
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

USE_TOOLS+=	gmake

NO_CONFIGURE=	yes

BUILD_TARGET=	# empty

SUBST_CLASSES+=		libelf
SUBST_STAGE.libelf=	post-patch
SUBST_FILES.libelf=	dynamips.h rom2c.c
SUBST_SED.libelf=	-e 's,<libelf.h>,<libelf/libelf.h>,'
SUBST_MESSAGE.libelf=	Fix libelf header file path

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dynamips ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nvram_export ${DESTDIR}${PREFIX}/bin

.include "../../devel/libelf/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
