# $NetBSD: Makefile,v 1.12 2003/09/27 17:07:34 grant Exp $

DISTNAME=	mp3blaster-3.1.3
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	ftp://mud.stack.nl/pub/mp3blaster/ \
		http://mp3blaster.linuxave.net/src/

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

.include "../../audio/libvorbis/buildlink2.mk"
.include "../../mk/curses.buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
