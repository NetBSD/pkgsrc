# $NetBSD: Makefile,v 1.46 2004/04/14 14:41:34 adam Exp $
#

DISTNAME=	TiMidity++-2.13.0
PKGNAME=	${DISTNAME:S/TiMidity++/timidity/}
CATEGORIES=     audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=timidity/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://timidity.sourceforge.net/
COMMENT=	MIDI to WAV renderer and player

CONFLICTS=	kdemultimedia-[0-9]*

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-vt100 --enable-audio=sun,vorbis
CONFIGURE_ARGS+=	--enable-gtk --enable-wrd --enable-xaw --enable-ncurses
CONFIGURE_ARGS+=	--with-ogg-prefix="${BUILDLINK_DIR}/include"
CONFIGURE_ARGS+=	--with-vorbis-prefix="${BUILDLINK_DIR}/include"

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
