# $NetBSD: Makefile,v 1.15 2003/12/03 12:31:36 cube Exp $

DISTNAME=	mp3blaster-3.2.0
CATEGORIES=	audio
MASTER_SITES=	http://www.stack.nl/~brama/mp3blaster/src/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.stack.nl/~brama/mp3blaster.html
COMMENT=	MP3 console curses-based player

PTHREAD_OPTS=	require
USE_BUILDLINK2=	yes
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+="--with-cxxflags=${CXXFLAGS}" \
		--with-curses \
		--with-oggvorbis

.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "pth")
CONFIGURE_ARGS+=	--enable-newthreads
.endif

post-extract:
	${MKDIR} ${WRKSRC}/getopt
	${MV} ${WRKSRC}/nmixer/getopt.h ${WRKSRC}/nmixer/getopt.c ${WRKSRC}/nmixer/getopt1.c \
		${WRKSRC}/getopt
	${RM} ${WRKSRC}/src/getopt.h ${WRKSRC}/src/getopt.c ${WRKSRC}/src/getopt1.c

.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
