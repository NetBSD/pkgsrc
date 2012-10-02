# $NetBSD: Makefile,v 1.86 2012/10/02 23:48:11 asau Exp $

DISTNAME=	TiMidity++-2.14.0
PKGNAME=	${DISTNAME:S/TiMidity++/timidity/}
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=timidity/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://timidity.sourceforge.net/
COMMENT=	MIDI to WAV renderer and player
LICENSE=	gnu-gpl-v2

CONFLICTS=		kdemultimedia-2.*{,nb*}

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-vt100
CONFIGURE_ARGS+=	--enable-ncurses
CONFIGURE_ARGS+=	--enable-server
CONFIGURE_ARGS+=	--with-ogg="${BUILDLINK_DIR}/include"
CONFIGURE_ARGS+=	--with-vorbis="${BUILDLINK_DIR}/include"
CONFIGURE_ARGS+=	--with-libFLAC="${BUILDLINK_DIR}/include"
CONFIGURE_ARGS+=	--with-default-path=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-audio=${TIMIDITY_NATIVE_AUDIO},ao,vorbis,flac,speex
CONFIGURE_ARGS+=	--enable-network

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--enable-alsaseq
.endif

SUBST_CLASSES+=		confdir
SUBST_MESSAGE.confdir=	Configuring to use PKG_SYSCONFDIR.
SUBST_STAGE.confdir=	post-patch
SUBST_FILES.confdir=	doc/C/timidity.cfg.5 doc/ja_JP.eucJP/timidity.cfg.5
SUBST_SED.confdir=	-e 's,/usr/local/share/timidity,${PKG_SYSCONFDIR},g'

TIMIDITY_NATIVE_AUDIO=	# empty

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS" || ${OPSYS} == "OpenBSD"
TIMIDITY_NATIVE_AUDIO=	sun
.elif ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
TIMIDITY_NATIVE_AUDIO=	oss
.elif ${OPSYS} == "Linux"
TIMIDITY_NATIVE_AUDIO=	alsa,oss
.elif ${OPSYS} == "Darwin"
TIMIDITY_NATIVE_AUDIO=	darwin
.endif

EGDIR=${PREFIX}/share/examples/timidity
CONF_FILES=${EGDIR}/timidity.cfg ${PKG_SYSCONFDIR}/timidity.cfg

pre-configure:
	${SED} "s|@PREFIX@|${PREFIX}|" < ${FILESDIR}/timidity.cfg > \
		${WRKDIR}/timidity.cfg

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/timidity.cfg ${DESTDIR}${EGDIR}

.include "options.mk"

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
