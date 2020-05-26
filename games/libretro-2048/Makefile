# $NetBSD: Makefile,v 1.2 2020/05/26 09:45:11 nia Exp $

DISTNAME=	libretro-2048-20181229
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	libretro-2048
GITHUB_TAG=	bc05dc6e504e78fd4eaf7bf91f5b3f84a93c2962

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/2048/
COMMENT=	Libretro core based on the 2048 puzzle game
LICENSE=	unlicense

USE_TOOLS+=	gmake
MAKE_FILE=	Makefile.libretro

OPSYSVARS+=	SOEXT
SOEXT.Darwin=	dylib
SOEXT.*=	so
PLIST_SUBST+=	SOEXT=${SOEXT}

CHECK_PORTABILITY_SKIP+=	pixman/configure

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--no-undefined

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/2048_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/2048_libretro.so

.include "../../mk/bsd.pkg.mk"
