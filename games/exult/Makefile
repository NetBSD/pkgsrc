# $NetBSD: Makefile,v 1.28 2020/03/20 11:57:40 nia Exp $

DISTNAME=	exult-1.4.9rc1
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=exult/exult-all-versions/}

MAINTAINER=	nikkohigashi@gmail.com
HOMEPAGE=	http://exult.sourceforge.net/
COMMENT=	Open-source Ultima 7 engine
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c gnu++03
USE_TOOLS+=	yacc flex

CFLAGS+=		-fpermissive
LDFLAGS+=		-lz
CONFIGURE_ARGS+=	--disable-sdltest --disable-oggtest --disable-vorbistest

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
