# $NetBSD: Makefile,v 1.1 2024/10/19 08:23:15 nia Exp $

DISTNAME=	Supermodel_0.2a_Src
PKGNAME=	${DISTNAME:tl:S/_src//1:S/_/-/g}
CATEGORIES=	emulators
MASTER_SITES=	https://www.supermodel3.com/Files/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.supermodel3.com/index.html
COMMENT=	Sega Model 3 Arcade Emulator
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
MAKE_FILE=	Makefiles/Makefile.SDL.UNIX.GCC

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Linux"
CFLAGS+=	-DUSE_FILE32API=1
.endif

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/supermodel

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/Supermodel \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Docs/*.txt \
		${DESTDIR}${PREFIX}/share/doc/supermodel

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
