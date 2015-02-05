# $NetBSD: Makefile,v 1.2 2015/02/05 17:15:52 jmcneill Exp $

DISTNAME=	snes9x-next-libretro-20150204
PKGNAME=	libretro-snes9x-next-20150204
CATEGORIES=	emulators
MASTER_SITES=	http://ftp.NetBSD.org/pub/NetBSD/misc/jmcneill/retroarch/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libretro/snes9x-next
COMMENT=	Libretro core based on the SNES9x 1.52+ emulator

WRKSRC=	${WRKDIR}/snes9x-next-master
USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_ARCH:M*arm*hf)
SNES9X_NEXT_PLATFORM=	${MACHINE_ARCH}-hardfloat
.else
SNES9X_NEXT_PLATFORM=	unix
.endif

MAKE_ENV+=	platform="${SNES9X_NEXT_PLATFORM}"

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/snes9x_next_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/snes9x_next_libretro.so

.include "../../mk/bsd.pkg.mk"
