# $NetBSD: Makefile,v 1.5 2020/05/26 09:45:14 nia Exp $

DISTNAME=	libretro-fceumm-20190106
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_TAG=	3efe223f135e2da1bd04909b30cf480fa62fe9d4

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/fceumm/
COMMENT=	Libretro core based on the FCEUmm Famicom/NES emulator
LICENSE=	gnu-gpl-v2

MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake

OPSYSVARS+=	SOEXT
SOEXT.Darwin=	dylib
SOEXT.*=	so
PLIST_SUBST+=	SOEXT=${SOEXT}

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/fceumm_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/fceumm_libretro.so

.include "../../mk/bsd.pkg.mk"
