# $NetBSD: Makefile,v 1.26 2004/05/24 18:17:18 drochner Exp $
# $Id: Makefile,v 1.26 2004/05/24 18:17:18 drochner Exp $

DISTNAME=	audacity-src-1.2.1
PKGNAME=	audacity-1.2.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=audacity/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://audacity.sourceforge.net/
COMMENT=	Audio editor

DEPENDS+=	zip>=0.0:../../archivers/zip

WRKSRC=			${WRKDIR}/audacity-src-1.2.1
USE_BUILDLINK3=		# defined
USE_X11=		# defined
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--without-xaudio
CONFIGURE_ARGS+=	--with-id3=system
CONFIGURE_ARGS+=	--with-libmad=system
CONFIGURE_ARGS+=	--with-vorbis=system
CONFIGURE_ARGS+=	--with-portaudio=system

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/lib-src/libsndfile/libtool \
			${WRKSRC}/lib-src/libsndfile/ltconfig \
			${WRKSRC}/ltconfig

.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"

# XXX Internal compiler error with -O2
.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O
.endif
