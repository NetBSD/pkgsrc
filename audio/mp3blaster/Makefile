# $NetBSD: Makefile,v 1.44 2023/08/02 19:20:16 nia Exp $

DISTNAME=	mp3blaster-3.2.6
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3blaster/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://mp3blaster.sourceforge.net/
COMMENT=	MP3 console curses-based player
LICENSE=	gnu-gpl-v2

CONFLICTS=		splay-[0-9]*

PTHREAD_OPTS+=	require
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

GNU_CONFIGURE=	yes

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

CPPFLAGS.SunOS+=	-Du_int16_t=uint16_t -Du_int32_t=uint32_t
LIBS.SunOS+=		-lsocket -lnsl

CONFIGURE_ARGS+=	--without-esd

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "pth")
CONFIGURE_ARGS+=	--enable-newthreads
.endif

.include "options.mk"

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
