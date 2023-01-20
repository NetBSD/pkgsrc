# $NetBSD: configure-settings.mk,v 1.2 2023/01/20 13:08:07 adam Exp $
#
# This file handles packages that use CMake as their primary build
# system. For more information about CMake, see http://www.cmake.org/.
#
# Package-settable variables:
#
# CMAKE_MODULE_PATH_OVERRIDE
#	Deprecated
#	A list of files relative to WRKSRC in which the CMAKE_MODULE_PATH
#	variable is adjusted to include the path from the pkgsrc wrappers.
#	The file ${WRKSRC}/CMakeLists.txt is always appended to this list.
#
# CMAKE_PKGSRC_BUILD_FLAGS
#	If set to yes, disable compiler optimization flags associated
#	with the CMAKE_BUILD_TYPE setting (for pkgsrc these come in from
#	the user via variables like CFLAGS).  The default is yes, but you can
#	set it to no for pkgsrc packages that do not use a compiler to avoid
#	cmake "Manually-specified variables were not used by the project"
#	warnings associated with this variable.
#
# CMAKE_PREFIX_PATH
#	A list of directories to add the CMAKE_PREFIX_PATH cmake variable.
#	If a package installs its contents in ${PREFIX}/package instead of
#	${PREFIX} and it installs cmake modules there
#	"CMAKE_PREFIX_PATH += ${PREFIX}/package" should be in its
#	buildlink3.mk so that packages that depend on it can find its
#	cmake modules if they use cmake to build.
#
# CMAKE_USE_GNU_INSTALL_DIRS
#	If set to yes, set GNU standard installation directories with pkgsrc
#	configured settings.  The default is yes.
#
# CMAKE_INSTALL_PREFIX
#	Destination directory to install software. The default is ${PREFIX}.
#
# CMAKE_INSTALL_NAME_DIR
#       Destination directory to install shlibs, used by
#       install_name_tool(1) on macOS. The default is ${PREFIX}/lib.
#

_CMAKE_MOD_DIR=	${BUILDLINK_DIR}/cmake-Modules

.if !empty(USE_LANGUAGES) && ${INSTALL_UNSTRIPPED:Uno:tl} != yes
INSTALL_TARGET?=	install/strip
.endif

CMAKE_USE_GNU_INSTALL_DIRS?=	yes

CMAKE_INSTALL_PREFIX?=		${PREFIX}
CMAKE_INSTALL_NAME_DIR?=	${PREFIX}/lib

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_INSTALL_PREFIX}
.if ${CMAKE_PKGSRC_BUILD_FLAGS:U:tl} != no
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_PKGSRC_BUILD_FLAGS:BOOL=TRUE
.endif

.if ${OPSYS} != "Darwin"
# Arguably, we should pass CMAKE_BUILD_RPATH and CMAKE_INSTALL_RPATH
# both equal to ${PREFIX}/lib, and omit -Wl,-R from LDFLAGS, to align
# with how cmake thinks RPATH should be handled, but that is a
# somewhat risky change.
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_SKIP_RPATH:BOOL=TRUE
.else
# TODO: Explain this better.
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_SKIP_RPATH:BOOL=FALSE
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_NAME_DIR:PATH=${CMAKE_INSTALL_NAME_DIR}
.endif

.if defined(CMAKE_USE_GNU_INSTALL_DIRS) && ${CMAKE_USE_GNU_INSTALL_DIRS:tl} != no
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_LIBDIR:PATH=lib
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_MANDIR:PATH=${PKGMANDIR}
.  if defined(INFO_FILES)
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_INFODIR:PATH=${PKGINFODIR}
.  endif
.  if defined(USE_PKGLOCALEDIR) && ${USE_PKGLOCALEDIR:U:tl} != no
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_LOCALEDIR:PATH=${PKGLOCALEDIR}/locale
.  endif
.endif
.if !empty(MACHINE_PLATFORM:MDarwin-*-aarch64)
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_APPLE_SILICON_PROCESSOR=arm64
.endif

.if defined(CMAKE_PREFIX_PATH)
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_PREFIX_PATH:PATH=${CMAKE_PREFIX_PATH:ts;:Q}
.endif
