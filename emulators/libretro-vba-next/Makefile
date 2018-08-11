# $NetBSD: Makefile,v 1.3 2018/08/11 13:22:52 nia Exp $

DISTNAME=	libretro-vba-next-20180603
CATEGORIES=	emulators games
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	vba-next
GITHUB_TAG=	110ab08a8042cb215a04872e26244331aa90eed5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/vba_next/
COMMENT=	Libretro core based on the VBA Next Game Boy Advance emulator
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
USE_LANGUAGES+=	c c++03
USE_TOOLS+=	gmake

MAKE_FILE=	Makefile.libretro

MAKE_FLAGS+=	GIT_VERSION="-pkgsrc"

INSTALLATION_DIRS=	lib/libretro

do-install:
	${INSTALL_LIB} ${WRKSRC}/vba_next_libretro.so \
		${DESTDIR}${PREFIX}/lib/libretro/vba_next_libretro.so

.include "../../mk/bsd.pkg.mk"
