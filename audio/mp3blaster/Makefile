# $NetBSD: Makefile,v 1.1.1.1 2002/02/23 07:43:19 rxg Exp $
# FreeBSD Id: ports/audio/mp3blaster/Makefile,v 1.10 2001/08/20 05:45:57 greid Exp

DISTNAME=	mp3blaster-3.0p8
CATEGORIES=	audio
MASTER_SITES=	ftp://mud.stack.nl/pub/mp3blaster/ \
		http://mp3blaster.linuxave.net/src/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://www.stack.nl/~brama/mp3blaster.html
COMMENT=	MP3 console ncurses-based player

NEED_NCURSES=	YES

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+="--with-cxxflags=${CXXFLAGS}" \
		--with-oggvorbis \
		--with-pth \
		--enable-newthreads

.include "../../audio/libogg/buildlink.mk"
.include "../../audio/libvorbis/buildlink.mk"
.include "../../devel/pth/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
