# $NetBSD: Makefile,v 1.39 2005/10/03 20:42:58 joerg Exp $

DISTNAME=	audacity-src-1.2.3
PKGNAME=	audacity-1.2.3
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=audacity/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://audacity.sourceforge.net/
COMMENT=	Audio editor

DEPENDS+=	zip>=0.0:../../archivers/zip

WRKSRC=			${WRKDIR}/audacity-src-1.2.3
USE_TOOLS+=		autoconf gmake
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-xaudio
CONFIGURE_ARGS+=	--with-id3=system
CONFIGURE_ARGS+=	--with-libflac=system
CONFIGURE_ARGS+=	--with-libmad=system
CONFIGURE_ARGS+=	--with-libsndfile=system
CONFIGURE_ARGS+=	--with-portaudio=system
CONFIGURE_ARGS+=	--with-vorbis=system
CONFIGURE_ENV+=		WX_CONFIG=${LOCALBASE}/bin/wx24-config
LTCONFIG_OVERRIDE=	${WRKSRC}/lib-src/libsndfile/libtool \
			${WRKSRC}/lib-src/libsndfile/ltconfig \
			${WRKSRC}/ltconfig
CONFIG_GUESS_OVERRIDE?=		\
	config.guess */config.guess */*/config.guess */*/*/config.guess
CONFIG_SUB_OVERRIDE?=		\
	config.sub */config.sub */*/config.sub */*/*/config.sub

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/wxGTK24/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

# XXX Internal compiler error with -O2
.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O
.endif
