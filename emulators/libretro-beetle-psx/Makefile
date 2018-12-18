# $NetBSD: Makefile,v 1.7 2018/12/18 16:12:13 nia Exp $

.include "Makefile.common"

PKGREVISION=	2

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/beetle_psx/
COMMENT=	Libretro core based on the Mednafen PlayStation emulator

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_psx_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_psx_libretro.so

.include "../../mk/bsd.pkg.mk"
