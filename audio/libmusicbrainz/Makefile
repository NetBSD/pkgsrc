# $NetBSD: Makefile,v 1.1.1.1 2007/06/08 07:02:15 wiz Exp $

DISTNAME=	libmusicbrainz-3.0.0
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://musicbrainz.org/doc/libmusicbrainz
COMMENT=	MusicBrainz (user-maintained community music metadatabase) library

USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE=	libmusicbrainz3.pc.cmake

do-configure:
	cd ${WRKSRC} && cmake . -DCMAKE_INSTALL_PREFIX:STRING=${PREFIX:Q} \
		-DNEON_INCLUDE_DIR:PATH=${PREFIX:Q}/include/neon \
		-DCMAKE_INSTALL_RPATH:STRING=${PREFIX:Q}/lib \
		-DCMAKE_SKIP_BUILD_RPATH:BOOL=ON \
		-DCMAKE_BUILD_WITH_INSTALL_RPATH:BOOL=ON \
		-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=ON

# XXX: should be a dependency, but doesn't work on enough platforms
#.include "../../audio/libdiscid/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
BUILDLINK_API_DEPENDS.neon+=	neon>=0.25.0
.include "../../www/neon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
