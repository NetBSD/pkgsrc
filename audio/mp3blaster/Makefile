# $NetBSD: Makefile,v 1.33 2012/10/02 23:47:58 asau Exp $

DISTNAME=	mp3blaster-3.2.5
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3blaster/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://mp3blaster.sourceforge.net/
COMMENT=	MP3 console curses-based player

CONFLICTS=		splay-[0-9]*

PTHREAD_OPTS+=	require
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

GNU_CONFIGURE=	yes

CPPFLAGS.SunOS+=	-Du_int16_t=uint16_t -Du_int32_t=uint32_t
LIBS.SunOS+=		-lsocket -lnsl

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "pth")
CONFIGURE_ARGS+=	--enable-newthreads
.endif

.include "options.mk"

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
