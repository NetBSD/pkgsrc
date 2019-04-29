# $NetBSD: Makefile,v 1.8 2019/04/29 12:00:16 nia Exp $

.include "Makefile.common"

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/beetle_psx/
COMMENT=	Libretro core based on the Mednafen PlayStation emulator

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_psx_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_psx_libretro.so

.include "../../mk/bsd.pkg.mk"
