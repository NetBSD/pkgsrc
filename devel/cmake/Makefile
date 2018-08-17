# $NetBSD: Makefile,v 1.150 2018/08/17 19:06:35 abs Exp $

PKGREVISION= 1
.include "Makefile.version"

DISTNAME=	cmake-${CMAKE_VERSION}
CATEGORIES=	devel
MASTER_SITES=	https://cmake.org/files/v${CMAKE_API}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cmake.org/
COMMENT=	Cross platform make
LICENSE=	modified-bsd

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++11
GCC_REQD+=		4.8
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	bootstrap

BUILD_TARGET=		default_target

CONFIGURE_HAS_MANDIR=	no
CONFIGURE_ARGS+=	--mandir=/${PKGMANDIR}
CONFIGURE_ARGS+=	--docdir=/share/doc/cmake-${CMAKE_API}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--system-libs
# jsoncpp requires cmake to build, so use the one provided with cmake
CONFIGURE_ARGS+=	--no-system-jsoncpp

LDFLAGS.Darwin+=	-framework CoreServices # for LSOpenCFURLRef()
LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../mk/bsd.prefs.mk"

.if !empty(MAKE_JOBS)
CONFIGURE_ARGS+=	--parallel=${MAKE_JOBS}
.endif

PLIST_SUBST+=		CMAKE_API=${CMAKE_API}

# for Source/cmDependsJavaParser.cxx
UNLIMIT_RESOURCES=	datasize

# as of 2.4.6, x11 and fortran tests fail in pkgsrc
TEST_TARGET=		test

SUBST_CLASSES+=		cmake
SUBST_STAGE.cmake=	pre-configure
SUBST_MESSAGE.cmake=	Fixing LOCALBASE and X11 paths.
SUBST_FILES.cmake+=	Modules/FindX11.cmake
SUBST_FILES.cmake+=	Modules/Platform/UnixPaths.cmake
SUBST_VARS.cmake=	LOCALBASE X11BASE

pre-configure:
	${RM} -f ${WRKSRC}/Modules/*.orig ${WRKSRC}/Modules/Compiler/*.orig ${WRKSRC}/Modules/Platform/*.orig
	${LN} -f ${WRKSRC}/Modules/Platform/OpenBSD.cmake ${WRKSRC}/Modules/Platform/MirBSD.cmake
.for lang in C CXX Fortran
	${LN} -f ${WRKSRC}/Modules/Platform/SunOS-GNU-${lang}.cmake \
	    ${WRKSRC}/Modules/Platform/SunOS-Clang-${lang}.cmake
.endfor

INCOMPAT_CURSES=	NetBSD-[0-8].*-*

BUILDLINK_API_DEPENDS.libarchive+=	libarchive>=3.0.0
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../misc/rhash/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"

.if !exists(${BUILDLINK_INCDIRS.curses}/form.h) && \
     exists(${BUILDLINK_INCDIRS.curses}/ncurses/form.h)
CFLAGS+=	-I${BUILDLINK_INCDIRS.curses}/ncurses
CXXFLAGS+=	-I${BUILDLINK_INCDIRS.curses}/ncurses
.endif

.include "../../mk/bsd.pkg.mk"
