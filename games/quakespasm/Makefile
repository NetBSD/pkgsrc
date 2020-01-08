# $NetBSD: Makefile,v 1.7 2020/01/08 13:10:49 nia Exp $

DISTNAME=	quakespasm-0.93.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quakespasm/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://quakespasm.sourceforge.net/
COMMENT=	Enhanced Quake engine using SDL
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

MAKE_FLAGS+=	USE_SDL2=1
MAKE_FLAGS+=	MP3LIB=mpg123

WRKSRC=		${WRKDIR}/${DISTNAME}/Quake
BUILD_TARGET=	quakespasm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/quakespasm ${DESTDIR}${PREFIX}/bin

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
