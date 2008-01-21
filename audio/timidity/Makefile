# $NetBSD: Makefile,v 1.62 2008/01/21 21:32:36 heinz Exp $

DISTNAME=	TiMidity++-2.13.2
PKGNAME=	${DISTNAME:S/TiMidity++/timidity/}
PKGREVISION=	7
CATEGORIES=     audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=timidity/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://timidity.sourceforge.net/
COMMENT=	MIDI to WAV renderer and player

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		kdemultimedia-2.[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-vt100
CONFIGURE_ARGS+=	--enable-gtk --enable-wrd --enable-xaw --enable-ncurses
CONFIGURE_ARGS+=	--with-ogg="${BUILDLINK_DIR}/include"
CONFIGURE_ARGS+=	--with-vorbis="${BUILDLINK_DIR}/include"
CONFIGURE_ARGS+=	--with-default-path=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-audio=${TIMIDITY_NATIVE_AUDIO},vorbis,speex
# flac disabled since there is currently (20070111) no patch available
# that adapts timidity for the flac-1.1.3 API
#CONFIGURE_ARGS+=	--enable-audio=${TIMIDITY_NATIVE_AUDIO},vorbis,flac,speex
#CONFIGURE_ARGS+=	--with-libFLAC="${BUILDLINK_DIR}/include"

SUBST_CLASSES+=		confdir
SUBST_MESSAGE.confdir=	Configuring to use PKG_SYSCONFDIR.
SUBST_STAGE.confdir=    post-patch
SUBST_FILES.confdir=	doc/C/timidity.cfg.5 doc/ja_JP.eucJP/timidity.cfg.5
SUBST_SED.confdir=	-e 's,/usr/local/share/timidity,${PKG_SYSCONFDIR},g'

.include "../../mk/bsd.prefs.mk"

TIMIDITY_NATIVE_AUDIO=	# empty

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS"
TIMIDITY_NATIVE_AUDIO=	sun
.elif ${OPSYS} == "Linux"
TIMIDITY_NATIVE_AUDIO=	oss
.elif ${OPSYS} == "Darwin"
TIMIDITY_NATIVE_AUDIO=	darwin
.endif

# see above for reason this is not included
#.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
