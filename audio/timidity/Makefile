# $NetBSD: Makefile,v 1.34 2002/03/13 17:36:37 fredb Exp $
#

DISTNAME=	TiMidity++-2.11.3
PKGNAME=	${DISTNAME:S/TiMidity++/timidity/}
PKGREVISION=	1
CATEGORIES=     audio
MASTER_SITES=	http://www.goice.co.jp/member/mo/timidity/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.goice.co.jp/member/mo/timidity/
COMMENT=	MIDI to WAV renderer and player

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-vt100 --enable-audio=sun,vorbis --disable-debug \
		--enable-gtk --enable-wrd \
		--with-ogg-prefix="${BUILDLINK_DIR}/include" \
		--with-vorbis-prefix="${BUILDLINK_DIR}/include"

USE_BUILDLINK_ONLY=	yes

.include "../../audio/libvorbis/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
