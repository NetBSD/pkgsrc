# $NetBSD: Makefile,v 1.40 2003/07/17 21:23:31 grant Exp $
#

DISTNAME=	TiMidity++-2.11.3
PKGNAME=	${DISTNAME:S/TiMidity++/timidity/}
PKGREVISION=	4
CATEGORIES=     audio
MASTER_SITES=	http://www.goice.co.jp/member/mo/timidity/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.goice.co.jp/member/mo/timidity/
COMMENT=	MIDI to WAV renderer and player

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-vt100 --enable-audio=sun,vorbis --disable-debug \
		--enable-gtk --enable-wrd --enable-xaw --enable-ncurses \
		--with-ogg-prefix="${BUILDLINK_DIR}/include" \
		--with-vorbis-prefix="${BUILDLINK_DIR}/include"

USE_BUILDLINK2=	yes

.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/xaw.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
