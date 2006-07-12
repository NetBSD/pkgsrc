# $NetBSD: Makefile,v 1.2 2006/07/12 13:30:33 wiz Exp $
#

DISTNAME=		libtunepimp-0.4.2
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.musicbrainz.org/pub/musicbrainz/ \
			http://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://musicbrainz.org/products/tunepimp/index.html
COMMENT=		Library to support MusicBrainz enabled tagging (0.4 series)

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
CONFLICTS+=		tunepimp-[0-9]* trm-[0-9]*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
pre-configure:
	${ECHO} "#define HAVE_STATVFS 1" >> ${WRKSRC}/config.h.in
.endif

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../multimedia/mpeg4ip/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
