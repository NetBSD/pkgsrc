# $NetBSD: Makefile,v 1.4 2002/08/01 05:48:05 jlam Exp $

DISTNAME=	mp3blaster-3.1.1
CATEGORIES=	audio
MASTER_SITES=	ftp://mud.stack.nl/pub/mp3blaster/ \
		http://mp3blaster.linuxave.net/src/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://www.stack.nl/~brama/mp3blaster.html
COMMENT=	MP3 console curses-based player

PTHREAD_OPTS=	require

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+="--with-cxxflags=${CXXFLAGS}" \
		--with-curses \
		--with-oggvorbis \
		--enable-newthreads

.include "../../audio/libogg/buildlink.mk"
.include "../../audio/libvorbis/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/ossaudio.buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
