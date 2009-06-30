# $NetBSD: Makefile,v 1.28 2009/06/30 00:07:10 joerg Exp $

DISTNAME=	mp3blaster-3.2.0
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.stack.nl/~brama/mp3blaster/src/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://mp3blaster.sourceforge.net/
COMMENT=	MP3 console curses-based player

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

PTHREAD_OPTS+=	require
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-cxxflags=${CXXFLAGS:Q} \
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
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
