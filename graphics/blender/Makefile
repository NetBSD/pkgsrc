# $NetBSD: Makefile,v 1.39 2005/03/04 16:04:59 reinoud Exp $
#

DISTNAME=		blender-2.36
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.cs.umn.edu/pub/blender.org/source/ \
			http://download.blender.org/source/

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://www.blender.org/
COMMENT=		Fully integrated 3D graphics creation suite

BUILD_DEPENDS+=		scons>=0.96:../../devel/scons

WRKSRC=			${WRKDIR}/blender

USE_X11=		YES
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES

LDFLAGS+=		-lcrypto

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		BLENDER_USE_OGG BLENDER_USE_VORBIS
BUILD_DEFS+=		BLENDER_USE_OPENAL BLENDER_USE_EXPPYTHON
BUILD_DEFS+=		BLENDER_INSTALL_DOC

post-patch:
	${MV} ${WRKSRC}/SConstruct ${WRKSRC}/SConstruct.orig
	${AWK} '{print} NR == 54 {print "env.Append(LINKFLAGS = \"-Wl,-R${X11BASE}/lib,-R${LOCALBASE}/lib\")"}' ${WRKSRC}/SConstruct.orig > ${WRKSRC}/SConstruct

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		ADD_C_INCLUDE_DIRS=${WRKDIR}/.buildlink/include ADD_C_LIB_DIRS=${WRKDIR}/.buildlink/lib \
		${PREFIX}/bin/scons -C ${WRKSRC} prefix=${PREFIX}

do-install:
	${CP} -f ${WRKSRC}/blender ${WRKSRC}/blender-bin
	${SED} -e "s|__PREFIX__|${PREFIX}|g" files/blender > ${TMP}/blender
	${CHMOD} +x ${TMP}/blender
	${INSTALL_PROGRAM} ${WRKSRC}/blender-bin ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/blender/scripts
	${INSTALL_DATA} ${WRKSRC}/release/scripts/* ${PREFIX}/share/blender/scripts
	${INSTALL} ${TMP}/blender ${PREFIX}/bin

.if defined(BLENDER_INSTALL_DOC)
DEPENDS+=		blender-doc:../../graphics/blender-doc
.endif

#
# disabled these options; they ought to be re-instantiated one day
#
.if 0
.if defined(BLENDER_USE_OGG)
CONFIGURE_ARGS+=	--with-ogg=${PREFIX}
.include "../../multimedia/libogg/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ogg --disable-oggtest
.endif

.if defined(BLENDER_USE_VORBIS)
CONFIGURE_ARGS+=	--with-vorbis=${PREFIX}
.include "../../audio/libvorbis/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-vorbis --disable-vorbistest
.endif

.if defined(BLENDER_USE_OPENAL)
CONFIGURE_ARGS+=	--enable-openal
.include "../../audio/openal/buildlink3.mk"
.endif

.if defined(BLENDER_USE_EXPPYTHON)
CONFIGURE_ARGS+=	--enable-exppython
.else
CONFIGURE_ARGS+=	--disable-exppython
.endif
.endif

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../lang/python/pyversion.mk"

.include "../../mk/bsd.pkg.mk"
