# $NetBSD: Makefile,v 1.40 2008/09/13 10:53:51 markd Exp $

DISTNAME=	cmake-${CMAKE_API}.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.cmake.org/files/v2.6/

CMAKE_API=	2.6

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.cmake.org/
COMMENT=	Cross platform make

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_NCURSES=		yes
GNU_CONFIGURE=		yes

BUILD_TARGET=		default_target

CONFIGURE_HAS_MANDIR=	no
CONFIGURE_ARGS+=	--mandir=/${PKGMANDIR}
CONFIGURE_ARGS+=	--docdir=/share/doc/cmake-${CMAKE_API}
CONFIGURE_ARGS+=	--system-libs

PLIST_SUBST+=		CMAKE_API=${CMAKE_API}

# for Source/cmDependsJavaParser.cxx
UNLIMIT_RESOURCES=	datasize

# as of 2.4.6, x11 and fortran tests fail in pkgsrc
TEST_TARGET=		test

SUBST_CLASSES+=		cmake
SUBST_STAGE.cmake=	pre-configure
SUBST_MESSAGE.cmake=	Fixing hard-coded prefix.
SUBST_FILES.cmake=	${REPLACE_CMAKE.Modules:@m@Modules/${m}.cmake@}
SUBST_FILES.cmake+=	Modules/FindCURL.cmake
SUBST_SED.cmake=	-e 's|/usr/X11R6|${X11BASE}|g'
SUBST_SED.cmake+=	-e 's|/usr/local|${LOCALBASE}|g'
SUBST_VARS.cmake=	PREFIX

REPLACE_CMAKE.Modules=\
	CMakeDetermineJavaCompiler CMakeDetermineSystem 		\
	CMakeGenericSystem FindAVIFile FindBLAS FindFLTK FindFLTK2 	\
	FindFreetype FindGDAL FindGIF FindGTK FindITK FindJNI 		\
	FindJava FindKDE3 FindLAPACK FindLua50 FindLua51 FindMPEG 	\
	FindMPEG2 FindMPI FindMatlab FindOpenAL FindOpenThreads		\
	FindPHP4 FindPNG FindPhysFS FindPike FindProducer FindQt	\
	FindQt3 FindSDL FindSDL_image FindSDL_mixer FindSDL_net 	\
	FindSDL_sound FindSDL_ttf FindSelfPackers FindTCL FindTclStub	\
	FindUnixCommands FindVTK FindX11 Findosg FindosgDB FindosgFX	\
	FindosgGA FindosgIntrospection FindosgManipulator		\
	FindosgParticle FindosgProducer FindosgShadow FindosgSim	\
	FindosgTerrain FindosgText FindosgUtil FindosgViewer		\
	GetPrerequisites Platform/UnixPaths UsePkgConfig

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/xmlrpc-c/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
