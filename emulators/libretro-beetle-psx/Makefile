# $NetBSD: Makefile,v 1.6 2018/12/18 15:50:48 nia Exp $

.include "Makefile.common"

PKGREVISION=	2

MAINTAINER=	nia@NetBSD.org
COMMENT=	Libretro core based on the Mednafen PlayStation emulator

do-install:
	${INSTALL_LIB} ${WRKSRC}/mednafen_psx_libretro.so \
	    ${DESTDIR}${PREFIX}/lib/libretro/mednafen_psx_libretro.so

.include "../../mk/bsd.pkg.mk"
