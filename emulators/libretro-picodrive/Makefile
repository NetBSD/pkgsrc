# $NetBSD: Makefile,v 1.1 2015/02/04 22:58:13 jmcneill Exp $

DISTNAME=	picodrive-libretro-20150203
PKGNAME=	libretro-picodrive-20150203
CATEGORIES=	emulators
MASTER_SITES=	http://ftp.netbsd.org/pub/NetBSD/misc/jmcneill/retroarch/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libretro/picodrive
COMMENT=	Fast MegaDrive/MegaCD/32X emulator
LICENSE=	picodrive-license

WRKSRC=		${WRKDIR}/picodrive
MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake

.if !empty(MACHINE_ARCH:M*armv6*)
MAKE_ENV+=	HAVE_ARMV6=1
.endif
.if !empty(MACHINE_ARCH:M*armv7*)
MAKE_ENV+=	HAVE_ARMV7=1
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/picodrive_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/picodrive_libretro.so

.include "../../mk/bsd.pkg.mk"
