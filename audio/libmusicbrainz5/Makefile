# $NetBSD: Makefile,v 1.6 2014/02/12 23:17:33 tron Exp $

DISTNAME=	libmusicbrainz-5.0.1
PKGNAME=	${DISTNAME:S/brainz/brainz5/}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://cloud.github.com/downloads/metabrainz/libmusicbrainz/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/libmusicbrainz
COMMENT=	MusicBrainz (user-maintained community music metadatabase) library v5
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE=	libmusicbrainz5.pc.cmake

CMAKE_ARGS+=	-DNEON_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.neon}/include/neon

LDFLAGS.SunOS+=	-lintl

#.include "../../audio/libdiscid/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.neon+=	neon>=0.25.0
.include "../../www/neon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
