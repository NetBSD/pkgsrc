# $NetBSD: Makefile,v 1.140 2018/08/16 18:54:51 adam Exp $

DISTNAME=	blender-2.77a
PKGREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	http://download.blender.org/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.blender.org/
COMMENT=	Fully integrated 3D graphics creation suite
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake sed
USE_CMAKE=		yes
USE_LANGUAGES=		c c++11
CMAKE_OPTS+=		-DWITH_OPENAL:BOOL=OFF
CMAKE_OPTS+=		-DWITH_MEM_JEMALLOC:BOOL=OFF
CMAKE_OPTS+=		-DPYVERSSUFFIX:STRING=${PYVERSSUFFIX}
CMAKE_OPTS+=		-DPYTHON_VERSION:STRING=${PYVERSSUFFIX}
CMAKE_OPTS+=		-DPYTHON_ROOT_DIR:STRING=${PREFIX}
CMAKE_OPTS+=		-DPYTHON_INCLUDE_DIR:STRING=${PREFIX}/${PYINC}
CMAKE_OPTS+=		-DPYTHON_INCLUDE_CONFIG_DIR:STRING=${PREFIX}/${PYINC}
CMAKE_OPTS+=		-DPYTHON_EXECUTABLE:FILEPATH=${PYTHONBIN}
CMAKE_OPTS+=		-DPYTHON_LIBRARY:FILEPATH=${PREFIX}/lib/libpython${PYVERSSUFFIX}.so
CMAKE_OPTS+=		-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX}/share/blender
CMAKE_OPTS+=		-DCMAKE_MODULE_PATH:PATH=${_CMAKE_DIR}
CMAKE_OPTS+=		-DCMAKE_SKIP_RPATH:BOOL=TRUE
CMAKE_OPTS+=		-DCMAKE_INSTALL_LIBDIR:PATH=lib
CMAKE_OPTS+=		-DCMAKE_INSTALL_MANDIR:PATH=man
CMAKE_OPTS+=		-DFREETYPE_INCLUDE_DIRS:PATH=${BUILDLINK_PREFIX.freetype2}/include/freetype2
CMAKE_OPTS+=		-DFREETYPE_LIBRARY:STRING=freetype
CMAKE_OPTS+=		-D_OPENGL_LIB_PATH:PATH=${BUILDLINK_PREFIX.MesaLib}/lib
CMAKE_OPTS+=		-D_OPENGL_INCLUDE_PATH:PATH=${BUILDLINK_PREFIX.MesaLib}/include
CMAKE_OPTS+=		-DOPENGL_glu_LIBRARY:STRING=GLU

CMAKE_OPTS+=		-DCMAKE_CXX_FLAGS:STRING=${CXXFLAGS:Q}

PYTHON_VERSIONS_INCOMPATIBLE=	27
GCC_REQD+=	4.7

DEPENDS+=	${PYPKGPREFIX}-expat>=0:../../textproc/py-expat
CMAKE_OPTS+=		-DWITH_PYTHON_INSTALL_NUMPY:BOOL=OFF
CMAKE_OPTS+=		-DWITH_PYTHON_INSTALL_REQUESTS:BOOL=OFF

REPLACE_PYTHON=		release/bin/blender-thumbnailer.py

.include "options.mk"

INSTALLATION_DIRS=	bin share/blender

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PLIST_SUBST+=	BLENDERVER=${PKGVERSION_NOREV:C/[a-z]//}

.if !empty(MACHINE_PLATFORM:MNetBSD-8.*)
PLIST_SUBST+=	NETBSDVER=netbsd8
.elif !empty(MACHINE_PLATFORM:MNetBSD-7.*)
PLIST_SUBST+=	NETBSDVER=netbsd7
.else
PLIST_SUBST+=	NETBSDVER=netbsd6
.endif

PLIST_VARS+=	py34 py35 py36

OBJDIR=		../build
CONFIGURE_DIRS=	${OBJDIR}
CMAKE_ARG_PATH=	../${DISTNAME}

pre-configure:
	${MKDIR} ${WRKSRC}/${OBJDIR}

# Install to custom CMAKE_INSTALL_PREFIX.
do-configure:
	cd ${WRKSRC}/${OBJDIR} && \
		env ${CONFIGURE_ENV} \
		${PREFIX}/bin/cmake ${CMAKE_OPTS} ${CMAKE_ARG_PATH}

post-install:
	${LN} -sf ${PREFIX}/share/blender/blender \
		${DESTDIR}${PREFIX}/bin

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
#.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/openimageio/buildlink3.mk"
.include "../../graphics/openjpeg15/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
#.include "../../multimedia/ffmpeg010/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../lang/python/application.mk"

.if ${PYVERSSUFFIX} == "3.4"
PLIST.py34=	yes
.elif ${PYVERSSUFFIX} == "3.5"
PLIST.py35=	yes
.elif ${PYVERSSUFFIX} == "3.6"
PLIST.py36=	yes
.endif

.include "../../mk/bsd.pkg.mk"
