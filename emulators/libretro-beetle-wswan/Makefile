# $NetBSD: Makefile,v 1.1 2018/08/12 12:52:52 nia Exp $

DISTNAME=	libretro-beetle-wswan-20180620
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	beetle-wswan-libretro
GITHUB_TAG=	b4dc85b0ada2b27af3d4420439b0e4528363ef67

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/beetle_cygne/
COMMENT=	Libretro core based on the Mednafen Wonderswan emulator
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DMSB_FIRST
.endif

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_wswan_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_wswan_libretro.so

.include "../../mk/bsd.pkg.mk"
