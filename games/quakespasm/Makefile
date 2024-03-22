# $NetBSD: Makefile,v 1.23 2024/03/22 23:05:42 nia Exp $

DISTNAME=	quakespasm-0.96.1
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quakespasm/}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://quakespasm.sourceforge.net/
COMMENT=	Enhanced Quake engine using SDL
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

MAKE_FLAGS+=	USE_SDL2=1
MAKE_FLAGS+=	MP3LIB=mpg123

WRKSRC=		${WRKDIR}/${DISTNAME}/Quake
BUILD_TARGET=	quakespasm

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
MAKE_FLAGS+=	COMMON_LIBS="-framework OpenGL -lm"
LDFLAGS+=	-framework CoreFoundation
LDFLAGS+=	-framework IOKit
LDFLAGS+=	-lSDL2main
.endif

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/quakespasm ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/quakespasm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
