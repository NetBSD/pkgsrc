# $NetBSD: Makefile,v 1.50 2004/10/13 15:23:40 adam Exp $

DISTNAME=	TiMidity++-2.13.2
PKGNAME=	${DISTNAME:S/TiMidity++/timidity/}
CATEGORIES=     audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=timidity/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://timidity.sourceforge.net/
COMMENT=	MIDI to WAV renderer and player

CONFLICTS=	kdemultimedia-2.[0-9]*

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-vt100
CONFIGURE_ARGS+=	--enable-gtk --enable-wrd --enable-xaw --enable-ncurses
CONFIGURE_ARGS+=	--with-libFLAC="${BUILDLINK_DIR}/include"
CONFIGURE_ARGS+=	--with-ogg="${BUILDLINK_DIR}/include"
CONFIGURE_ARGS+=	--with-vorbis="${BUILDLINK_DIR}/include"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--enable-audio=sun,vorbis,flac,speex
.endif

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--enable-audio=oss,vorbis,flac,speex
.endif

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
