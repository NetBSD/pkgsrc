# $NetBSD: Makefile,v 1.9 2017/09/28 16:03:25 jperkin Exp $

DISTNAME=	mupen64plus-libretro-20150204
PKGNAME=	libretro-mupen64plus-20150204
PKGREVISION=	1
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

SUBST_CLASSES+=		d2u
SUBST_STAGE.d2u=	post-extract
SUBST_FILES.d2u=	mupen64plus-video-angrylion/n64video.c
SUBST_FILTER_CMD.d2u=	${TR} -d '\r'

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

CFLAGS.NetBSD+=	-DHAVE_POSIX_MEMALIGN=1

.include "options.mk"

do-install:
	${INSTALL_LIB} ${WRKSRC}/mupen64plus_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mupen64plus_libretro.so

.include "../../mk/bsd.pkg.mk"
