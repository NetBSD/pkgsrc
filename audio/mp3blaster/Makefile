# $NetBSD: Makefile,v 1.5 2002/08/31 13:05:13 wiz Exp $

DISTNAME=	mp3blaster-3.1.1
CATEGORIES=	audio
MASTER_SITES=	ftp://mud.stack.nl/pub/mp3blaster/ \
		http://mp3blaster.linuxave.net/src/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://www.stack.nl/~brama/mp3blaster.html
COMMENT=	MP3 console curses-based player

PTHREAD_OPTS=	require
USE_BUILDLINK2=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+="--with-cxxflags=${CXXFLAGS}" \
		--with-curses \
		--with-oggvorbis \
		--enable-newthreads

.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
