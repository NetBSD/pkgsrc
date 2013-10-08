# $NetBSD: cmake.mk,v 1.10 2013/10/08 12:03:53 obache Exp $
#
# This file handles packages that use CMake as their primary build
# system. For more information about CMake, see http://www.cmake.org/.
#
# === Package-settable variables ===
#
# CMAKE_DEPENDENCIES_REWRITE
#	A list of files (XXX: variable name) relative to WRKSRC in
#	which, after configuring the package, buildlink3 dependencies
#	are resolved to the real ones.
#
# CMAKE_MODULE_PATH_OVERRIDE
#	A list of files relative to WRKSRC in which the CMAKE_MODULE_PATH
#	variable is adjusted to include the path from the pkgsrc wrappers.
#	The file ${WRKSRC}/CMakeLists.txt is always appended to this list.
#

_CMAKE_DIR=	${BUILDLINK_DIR}/cmake-Modules

CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX}
CMAKE_ARGS+=	-DCMAKE_MODULE_PATH:PATH=${_CMAKE_DIR}
CMAKE_ARGS+=	-DCMAKE_INSTALL_LIBDIR:PATH=lib
.if ${OPSYS} != "Darwin"
CMAKE_ARGS+=	-DCMAKE_SKIP_RPATH:BOOL=TRUE
.else
CMAKE_ARGS+=	-DCMAKE_SKIP_RPATH:BOOL=FALSE
CMAKE_ARGS+=	-DCMAKE_INSTALL_NAME_DIR:PATH=${PREFIX}/lib
CMAKE_ARGS+=	-DOPENAL_INCLUDE_DIR:PATH=/System/Library/Frameworks/OpenAL.framework/Headers
CMAKE_ARGS+=	-DOPENGL_INCLUDE_DIR:PATH=/System/Library/Frameworks/OpenGL.framework/Headers
.endif
CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR:PATH=${PKGMANDIR}
.if defined(INFO_FILES)
CMAKE_ARGS+=	-DCMAKE_INSTALL_INFODIR:PATH=${PKGINFODIR}
.endif
.if defined(USE_PKGLOCALEDIR) && empty(USE_PKGLOCALEDIR:M[nN][oO])
CMAKE_ARGS+=	-DCMAKE_INSTALL_LOCALEDIR:PATH=${PKGLOCALEDIR}/locale
.endif

CMAKE_MODULE_PATH_OVERRIDE+=	CMakeLists.txt

### configure-cmake-override modifies the cmake CMakeLists.txt file in
### ${WRKSRC} so that if CMAKE_MODULE_PATH is set we add our Module
### directory before any others.
###

SUBST_CLASSES+=		cmake
SUBST_STAGE.cmake=	do-configure-pre-hook
SUBST_MESSAGE.cmake=	Fixing CMAKE_MODULE_PATH in CMakeLists.txt
SUBST_FILES.cmake=	${CMAKE_MODULE_PATH_OVERRIDE}
SUBST_SED.cmake=	\
	's|set *( *CMAKE_MODULE_PATH |set (CMAKE_MODULE_PATH "${_CMAKE_DIR}" |'

do-configure-pre-hook: __cmake-copy-module-tree
__cmake-copy-module-tree: .PHONY
	${RUN} cd ${PKGSRCDIR}/mk; ${CP} -R cmake-Modules ${_CMAKE_DIR}

### The cmake function export_library_dependencies() writes out
### library dependency info to a file and this may contain buildlink
### paths.
### cmake-dependencies-rewrite modifies any such files, listed in
### ${CMAKE_DEPENDENCIES_REWRITE} (relative to ${WRKSRC}) to have the
### real dependencies
###

do-configure-post-hook: __cmake-dependencies-rewrite
__cmake-dependencies-rewrite: .PHONY
	@${STEP_MSG} "Rewrite cmake Dependencies files"
.if defined(CMAKE_DEPENDENCIES_REWRITE) && !empty(CMAKE_DEPENDENCIES_REWRITE)
	${RUN} \
	cd ${WRKSRC};							\
	for file in ${CMAKE_DEPENDENCIES_REWRITE}; do			\
		${TEST} -f "$$file" || continue;			\
		${AWK} -f ${PKGSRCDIR}/mk/configure/cmake-rewrite.awk ${BUILDLINK_DIR} $$file > $$file.override; \
		${MV} -f $$file.override $$file;			\
	done
.endif
