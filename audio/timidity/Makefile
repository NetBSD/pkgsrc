# $NetBSD: Makefile,v 1.31 2002/01/17 01:20:39 wiz Exp $
#

DISTNAME=	TiMidity++-2.11.2
PKGNAME=	${DISTNAME:S/TiMidity++/timidity/}
CATEGORIES=     audio
MASTER_SITES=	http://www.goice.co.jp/member/mo/timidity/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
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
