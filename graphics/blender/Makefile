# $NetBSD: Makefile,v 1.29 2004/01/24 15:46:43 grant Exp $
#

DISTNAME=		blender-2.31a
PKGNAME=		blender-2.31.0.1
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.cs.umn.edu/pub/blender.org/source/ \
			http://download.blender.org/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://www.blender.org/
COMMENT=		Fully integrated 3D graphics creation suite

USE_X11=		YES
HAS_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

LDFLAGS+=		-lcrypto

CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}
CONFIGURE_ARGS+=	--prefix=${PREFIX} --without-ode

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		BLENDER_USE_OGG BLENDER_USE_VORBIS
BUILD_DEFS+=		BLENDER_USE_OPENAL BLENDER_USE_EXPPYTHON
BUILD_DEFS+=		BLENDER_INSTALL_DOC

.if defined(BLENDER_INSTALL_DOC)
DEPENDS+=		blender-doc:../../graphics/blender-doc
.endif

.if defined(BLENDER_USE_OGG)
CONFIGURE_ARGS+=	--with-ogg=${PREFIX}
.include "../../audio/libogg/buildlink2.mk"
.else
CONFIGURE_ARGS+=	--without-ogg --disable-oggtest
.endif

.if defined(BLENDER_USE_VORBIS)
CONFIGURE_ARGS+=	--with-vorbis=${PREFIX}
.include "../../audio/libvorbis/buildlink2.mk"
.else
CONFIGURE_ARGS+=	--without-vorbis --disable-vorbistest
.endif

.if defined(BLENDER_USE_OPENAL)
CONFIGURE_ARGS+=	--enable-openal
.include "../../audio/openal/buildlink2.mk"
.endif

.if defined(BLENDER_USE_EXPPYTHON)
CONFIGURE_ARGS+=	--enable-exppython
.else
CONFIGURE_ARGS+=	--disable-exppython
.endif

.include "../../audio/openal/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../devel/libtool/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../lang/python/pyversion.mk"

.include "../../mk/bsd.pkg.mk"
