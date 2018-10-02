# $NetBSD: Makefile,v 1.3 2018/10/02 21:09:30 nia Exp $

DISTNAME=	libretro-stella-20180411
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	stella-libretro
GITHUB_TAG=	b0d525b724fa0a9a313e2ea33a590aba98deaabf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/stella/
COMMENT=	Libretro core based on the Stella Atari 2600 (VCS) emulator
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

MAKE_FLAGS+=	GIT_VERSION="-${PKGVERSION_NOREV}-pkgsrc"

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--no-undefined
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=link.T

INSTALLATION_DIRS+=	${PREFIX}/lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/stella_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/stella_libretro.so

.include "../../mk/bsd.pkg.mk"
