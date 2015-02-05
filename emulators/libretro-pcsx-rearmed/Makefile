# $NetBSD: Makefile,v 1.3 2015/02/05 17:17:11 wiz Exp $

DISTNAME=	pcsx-rearmed-libretro-20150204
PKGNAME=	libretro-pcsx-rearmed-20150204
CATEGORIES=	emulators
MASTER_SITES=	http://ftp.NetBSD.org/pub/NetBSD/misc/jmcneill/retroarch/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libretro/pcsx_rearmed
COMMENT=	Libretro core based on the PCSX ReARMed emulator
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/pcsx_rearmed-master
HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=--platform=libretro

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

BUILDLINK_TRANSFORM+=	rm:-ldl

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_ARCH:M*arm*hf)
CFLAGS+=	-mfloat-abi=hard
ASFLAGS+=	-mfloat-abi=hard
.endif

.if !empty(MACHINE_ARCH:M*arm*)
# only ARM-specific options for now, and options framework
#insists on having at least one option, so only pull it in for ARM
.include "options.mk"
.endif

do-install:
	${INSTALL_LIB} ${WRKSRC}/libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/pcsx_rearmed_libretro.so

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
