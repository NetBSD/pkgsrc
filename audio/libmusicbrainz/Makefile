# $NetBSD: Makefile,v 1.13 2014/02/12 23:17:33 tron Exp $

DISTNAME=	libmusicbrainz-3.0.3
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/libmusicbrainz
COMMENT=	MusicBrainz (user-maintained community music metadatabase) library v3
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE=	libmusicbrainz3.pc.cmake

CMAKE_ARGS+=	-DNEON_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.neon}/include/neon

.include "../../audio/libdiscid/buildlink3.mk"
BUILDLINK_API_DEPENDS.neon+=	neon>=0.25.0
.include "../../www/neon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
