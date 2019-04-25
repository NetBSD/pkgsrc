# $NetBSD: Makefile,v 1.4 2019/04/25 13:46:11 nia Exp $

DISTNAME=	libretro-bluemsx-20190420
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	blueMSX-libretro
GITHUB_TAG=	fe31638aed9c12ed8218965506c3054f11fabf7c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/bluemsx/
COMMENT=	Libretro core for MSX/MSX2/ColecoVision/SVI/SG-1000 emulation
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
MAKE_FILE=	Makefile.libretro
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++03

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.include "../../mk/bsd.prefs.mk"

# For strcasestr
# See dc61b353c3bea0c088b3f827cfbd864460b112a0, pull/33
.if ${OPSYS} == "NetBSD"
CFLAGS+=	-D_NETBSD_SOURCE
.elif ${OPSYS} == "SunOS"
CFLAGS+=	-D__EXTENSIONS__
.elif ${OPSYS} != "Linux"
CFLAGS+=	-D_GNU_SOURCE -D_BSD_SOURCE
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-version-script=link.T
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-no-undefined

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/bluemsx_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/bluemsx_libretro.so

.include "../../mk/bsd.pkg.mk"
