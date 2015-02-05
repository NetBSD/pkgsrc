# $NetBSD: Makefile,v 1.2 2015/02/05 16:57:53 wiz Exp $

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
.if !empty(MACHINE_ARCH:M*arm*hf)
CFLAGS+=	-mfloat-abi=hard
ASFLAGS+=	-mfloat-abi=hard
.endif

do-install:
	${INSTALL_LIB} ${WRKSRC}/libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/pcsx_rearmed_libretro.so

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
