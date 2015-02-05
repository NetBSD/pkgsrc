# $NetBSD: Makefile,v 1.4 2015/02/05 17:22:26 wiz Exp $

DISTNAME=	mupen64plus-libretro-20150204
PKGNAME=	libretro-mupen64plus-20150204
CATEGORIES=	emulators
MASTER_SITES=	http://ftp.NetBSD.org/pub/NetBSD/misc/jmcneill/retroarch/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libretro/mupen64plus-libretro
COMMENT=	Libretro core based on the Mupen64 Plus emulator
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/mupen64plus-libretro-master
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

SUBST_CLASSES+=		vc
SUBST_STAGE.vc=		pre-configure
SUBST_MESSAGE.vc=	Fixing path to VideoCore libraries.
SUBST_FILES.vc=		Makefile
SUBST_SED.vc+=		-e 's;/opt/vc;${PREFIX};g'

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CFLAGS+=	-DHAVE_POSIX_MEMALIGN=1
.endif

.if !empty(MACHINE_ARCH:M*arm*)
# only ARM-specific options for now, and options framework
#insists on having at least one option, so only pull it in for ARM
.include "options.mk"
.endif

do-install:
	${INSTALL_LIB} ${WRKSRC}/mupen64plus_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mupen64plus_libretro.so

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
