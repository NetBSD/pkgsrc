# $NetBSD: Makefile,v 1.31 2004/11/22 16:36:31 adam Exp $

DISTNAME=	audacity-src-1.2.3
PKGNAME=	audacity-1.2.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=audacity/}

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://audacity.sourceforge.net/
COMMENT=	Audio editor

DEPENDS+=	zip>=0.0:../../archivers/zip

WRKSRC=			${WRKDIR}/audacity-src-1.2.3
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-xaudio
CONFIGURE_ARGS+=	--with-id3=system
CONFIGURE_ARGS+=	--with-libflac=system
CONFIGURE_ARGS+=	--with-libmad=system
CONFIGURE_ARGS+=	--with-libsndfile=system
CONFIGURE_ARGS+=	--with-portaudio=system
CONFIGURE_ARGS+=	--with-vorbis=system
LTCONFIG_OVERRIDE=	${WRKSRC}/lib-src/libsndfile/libtool \
			${WRKSRC}/lib-src/libsndfile/ltconfig \
			${WRKSRC}/ltconfig

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"

# XXX Internal compiler error with -O2
.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O
.endif
