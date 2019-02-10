# $NetBSD: Makefile,v 1.1 2019/02/10 12:39:10 nia Exp $

DISTNAME=	libretro-2048-20181229
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	libretro-2048
GITHUB_TAG=	bc05dc6e504e78fd4eaf7bf91f5b3f84a93c2962

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/2048/
COMMENT=	Libretro core based on the 2048 puzzle game
LICENSE=	unlicense

EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake
MAKE_FILE=	Makefile.libretro

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
