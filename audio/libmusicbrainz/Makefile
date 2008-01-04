# $NetBSD: Makefile,v 1.2 2008/01/04 20:10:10 markd Exp $

DISTNAME=	libmusicbrainz-3.0.0
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/libmusicbrainz
COMMENT=	MusicBrainz (user-maintained community music metadatabase) library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE=	libmusicbrainz3.pc.cmake

CMAKE_ARGS+=	-DNEON_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.neon}/include/neon

# XXX: should be a dependency, but doesn't work on enough platforms
#.include "../../audio/libdiscid/buildlink3.mk"
BUILDLINK_API_DEPENDS.neon+=	neon>=0.25.0
.include "../../www/neon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
