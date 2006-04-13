# $NetBSD: Makefile,v 1.2 2006/04/13 06:14:25 wiz Exp $
#

DISTNAME=		libtunepimp-0.4.2
CATEGORIES=		audio
MASTER_SITES=		ftp://ftp.musicbrainz.org/pub/musicbrainz/ \
			http://ftp.musicbrainz.org/pub/musicbrainz/ \
			ftp://ftp.nl.musicbrainz.org/ \
			ftp://ftp.au.musicbrainz.org/pub/musicbrainz/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://musicbrainz.org/products/tunepimp/index.html
COMMENT=		Library to support MusicBrainz enabled tagging

GNU_CONFIGURE=		YES
CONFLICTS+=		tunepimp-[0-9]*

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../multimedia/mpeg4ip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
