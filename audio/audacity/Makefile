# $NetBSD: Makefile,v 1.17 2003/12/08 14:41:38 wiz Exp $

DISTNAME=	audacity-src-1.0.0-2
PKGNAME=	audacity-1.0.0.2
PKGREVISION=	5
WRKSRC=		${WRKDIR}/audacity-src-1.0.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=audacity/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://audacity.sourceforge.net/
COMMENT=	Audio editor

BUILD_DEPENDS+=	zip-[0-9]*:../../archivers/zip

USE_BUILDLINK2=		# defined
USE_X11=		# defined
USE_GMAKE=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--without-xaudio
CONFIGURE_ARGS+=	--with-id3
CONFIGURE_ARGS+=	--with-libmad
CONFIGURE_ARGS+=	--with-vorbis
CONFIGURE_ARGS+=	--with-dev-dsp="${DEVOSSSOUND}"
CONFIGURE_ARGS+=	--with-helpdir="${PREFIX}/share"
HAVE_OSS=		NO

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/id3lib/ltconfig

pre-configure:
	cd ${WRKSRC}/id3lib/include/id3; ${MV} -f strings.h id3_strings.h
	cd ${WRKSRC}/id3lib; for file in				\
		`${FIND} . -type f -print |				\
			${XARGS} ${GREP} -l "\"strings\.h\""`; do	\
		${SED}	-e "s|\"strings\.h\"|\"id3_strings.h\"|g"	\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done
	cd ${WRKSRC} && ${AUTOCONF}

.include "../../audio/id3lib/buildlink2.mk"
.include "../../audio/lame/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../audio/libmad/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../x11/wxGTK/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"

# XXX Internal compiler error with -O2
.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O
.endif
