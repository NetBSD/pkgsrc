# $NetBSD: Makefile,v 1.40 2018/12/09 21:05:32 adam Exp $

DISTNAME=	mp3blaster-3.2.6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3blaster/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://mp3blaster.sourceforge.net/
COMMENT=	MP3 console curses-based player
LICENSE=	gnu-gpl-v2

CONFLICTS=		splay-[0-9]*

PTHREAD_OPTS+=	require
USE_LANGUAGES=	c c++03
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
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
