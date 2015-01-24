# $NetBSD: Makefile,v 1.93 2015/01/24 16:55:20 wiz Exp $

DISTNAME=	cmake-${CMAKE_API}.1
CATEGORIES=	devel
MASTER_SITES=	http://www.cmake.org/files/v${CMAKE_API}/

CMAKE_API=	3.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cmake.org/
COMMENT=	Cross platform make
LICENSE=	modified-bsd

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_NCURSES=		wsyncup
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	bootstrap

BUILD_TARGET=		default_target

CONFIGURE_HAS_MANDIR=	no
CONFIGURE_ARGS+=	--mandir=/${PKGMANDIR}
CONFIGURE_ARGS+=	--docdir=/share/doc/cmake-${CMAKE_API}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--system-libs

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../mk/bsd.prefs.mk"

.if !empty(MAKE_JOBS)
CONFIGURE_ARGS+=	--parallel=${MAKE_JOBS:Q}
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

SUBST_CLASSES+=		flags
SUBST_STAGE.flags=	pre-configure
SUBST_MESSAGE.flags=	Fixing compiler flags.
SUBST_FILES.flags=	Modules/Compiler/*.cmake
SUBST_SED.flags=	-e 's,-O.,,'

pre-configure:
	${RM} -f ${WRKSRC}/Modules/*.orig ${WRKSRC}/Modules/Platform/*.orig
	${LN} -f ${WRKSRC}/Modules/Platform/OpenBSD.cmake ${WRKSRC}/Modules/Platform/MirBSD.cmake

BUILDLINK_API_DEPENDS.libarchive+=	libarchive>=2.8.4
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
