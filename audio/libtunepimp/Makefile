# $NetBSD: Makefile,v 1.28 2014/02/12 23:17:34 tron Exp $

DISTNAME=		libtunepimp-0.5.3
PKGREVISION=		14
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.musicbrainz.org/pub/musicbrainz/ \
			http://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://musicbrainz.org/doc/libtunepimp
COMMENT=		Library to support MusicBrainz enabled tagging
# alternatively, gnu-lgpl-v2 is also supported, but then the package
# would need to disable some plugins; so the pkgsrc version currently
# falls under gnu-gpl-v2
LICENSE=		gnu-gpl-v2

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
.include "../../audio/libmpcdec/buildlink3.mk"
.include "../../audio/libofa/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../multimedia/libmp4v2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
