# $NetBSD: Makefile,v 1.19 2004/10/03 00:13:08 tv Exp $

DISTNAME=	mp3blaster-3.2.0
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.stack.nl/~brama/mp3blaster/src/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.stack.nl/~brama/mp3blaster.html
COMMENT=	MP3 console curses-based player

PTHREAD_OPTS=	require
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+="--with-cxxflags=${CXXFLAGS}" \
		--with-curses \
		--with-oggvorbis

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "pth")
CONFIGURE_ARGS+=	--enable-newthreads
.endif

post-extract:
	${MKDIR} ${WRKSRC}/getopt
	${MV} ${WRKSRC}/nmixer/getopt.h ${WRKSRC}/nmixer/getopt.c \
		${WRKSRC}/nmixer/getopt1.c ${WRKSRC}/getopt
	${RM} ${WRKSRC}/src/getopt.h ${WRKSRC}/src/getopt.c \
		${WRKSRC}/src/getopt1.c

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
