# $NetBSD: Makefile,v 1.45 2004/04/12 00:31:18 snj Exp $
#

DISTNAME=	TiMidity++-2.11.3
PKGNAME=	${DISTNAME:S/TiMidity++/timidity/}
PKGREVISION=	5
CATEGORIES=     audio
MASTER_SITES=	http://www.goice.co.jp/member/mo/timidity/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.goice.co.jp/member/mo/timidity/
COMMENT=	MIDI to WAV renderer and player

CONFLICTS=	kdemultimedia-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-vt100 --enable-audio=sun,vorbis --disable-debug \
		--enable-gtk --enable-wrd --enable-xaw --enable-ncurses \
		--with-ogg-prefix="${BUILDLINK_DIR}/include" \
		--with-vorbis-prefix="${BUILDLINK_DIR}/include"

USE_BUILDLINK3=	yes

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
