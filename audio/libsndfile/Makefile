# $NetBSD: Makefile,v 1.98 2024/05/06 08:40:21 jperkin Exp $

DISTNAME=	libsndfile-1.2.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=libsndfile/}
GITHUB_PROJECT=	libsndfile
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libsndfile.github.io/libsndfile/
COMMENT=	Library for reading and writing audio files
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE=	sndfile.pc.in
GNU_CONFIGURE=		yes
PYTHON_FOR_BUILD_ONLY=	tool

USE_FEATURES+=		strnlen

TEST_TARGET=		check

.include "options.mk"

OPSYSVARS+=		BUILDLINK_PASSTHRU_DIRS

BUILDLINK_PASSTHRU_DIRS.Darwin+=	/Developer

.if !empty(PKGSRC_COMPILER:Msunpro)
CXXFLAGS+=		-features=extensions
.endif

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../lang/python/tool.mk"
BUILDLINK_API_DEPENDS.libogg+=	libogg>=1.1.3
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
