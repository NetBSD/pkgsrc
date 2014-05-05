# $NetBSD: Makefile,v 1.88 2014/05/05 00:47:35 ryoon Exp $

DISTNAME=		audacity-src-1.2.6
PKGREVISION=		26
PKGNAME=		${DISTNAME:S/-src-/-/}
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=audacity/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://audacity.sourceforge.net/
COMMENT=		Audio editor

MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf gmake msgfmt pkg-config zip:run
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-xaudio
CONFIGURE_ARGS+=	--with-id3=system
CONFIGURE_ARGS+=	--with-libmad=system
CONFIGURE_ARGS+=	--with-libsndfile=system
CONFIGURE_ARGS+=	--with-portaudio=system
CONFIGURE_ARGS+=	--with-vorbis=system
CONFIGURE_ENV+=		WX_CONFIG=${LOCALBASE}/bin/wx24-config

CONFIG_GUESS_OVERRIDE=		\
	config.guess */config.guess */*/config.guess */*/*/config.guess
CONFIG_SUB_OVERRIDE=		\
	config.sub */config.sub */*/config.sub */*/*/config.sub

PTHREAD_AUTO_VARS=	yes

.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/wxGTK24/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# XXX Internal compiler error with -O2
.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O
.endif
