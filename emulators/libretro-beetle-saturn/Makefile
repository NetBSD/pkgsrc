# $NetBSD: Makefile,v 1.5 2020/05/26 09:45:12 nia Exp $

DISTNAME=	libretro-beetle-saturn-20180620
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	beetle-saturn-libretro
GITHUB_TAG=	1983713f665e86459900a08873fac09e70c31bfa

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/beetle_saturn/
COMMENT=	Libretro core based on the Mednafen Sega Saturn emulator
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

OPSYSVARS+=	SOEXT
SOEXT.Darwin=	dylib
SOEXT.*=	so
PLIST_SUBST+=	SOEXT=${SOEXT}

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

# "experimental, x86_64 only" - https://mednafen.github.io/
# Not built by upstream's buildbot for i386, ARM, or PowerPC.
ONLY_FOR_PLATFORM=	*-*-x86_64

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=link.T
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--no-undefined

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_saturn_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_saturn_libretro.so

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
