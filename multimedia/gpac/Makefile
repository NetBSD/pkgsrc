# $NetBSD: Makefile,v 1.101 2024/05/16 06:15:14 wiz Exp $

DISTNAME=	gpac-1.0.1
PKGREVISION=	20
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=gpac/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gpac.io/
COMMENT=	Open source multimedia framework
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake grep gsed pkg-config
# not really GNU configure, but close enough
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-wx
CONFIGURE_ARGS+=	--enable-pic
CONFIGURE_ARGS+=	--extra-cflags="${CFLAGS}"
CONFIGURE_ARGS+=	--extra-ldflags="${LDFLAGS}"
CFLAGS+=		-I${BUILDLINK_PREFIX.faad2}/${BUILDLINK_INCDIRS.faad2}

# malloc_usable_size()
LDFLAGS.NetBSD+=	-ljemalloc

# Pre-generate header and avoid git dependency.
pre-build:
	${ECHO} "#define GPAC_GIT_REVISION \"release\"" > ${WRKSRC}/include/gpac/revision.h

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	darwin notdarwin
.if ${SHLIB_TYPE} == "dylib"
PLIST.darwin=	yes
PLIST_SUBST+=	LIBEXT=dylib
post-install:
	cd ${DESTDIR}${PREFIX} && find lib/gpac -name "*.dylib" | while read lib; do \
		install_name_tool -id ${PREFIX}/$${lib} $${lib}; \
	done
.else
PLIST.notdarwin=	yes
PLIST_SUBST+=		LIBEXT=so
.endif

.include "options.mk"
.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../multimedia/xvidcore/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/xmlrpc-c/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
