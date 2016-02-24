# $NetBSD: cmake.mk,v 1.13 2016/02/24 15:24:56 jperkin Exp $
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
# CMAKE_PREFIX_PATH
#	A list of directories to add the CMAKE_PREFIX_PATH cmake variable.
#	If a package installs it's contents in ${PREFIX}/package instead of
#	${PREFIX} and it installs cmake modules there 
#	"CMAKE_PREFIX_PATH += ${PREFIX}/package" should be in it's 
#	buildlink3.mk so that packages that depend on it can find it's 
#	cmake modules if they use cmake to build.
#
# CMAKE_USE_GNU_INSTALL_DIRS
#	If set to yes, set GNU standard installation directories with pkgsrc
#	configured settings.  The default is yes.
#

_CMAKE_DIR=	${BUILDLINK_DIR}/cmake-Modules

CMAKE_USE_GNU_INSTALL_DIRS?=	yes

CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX}
CMAKE_ARGS+=	-DCMAKE_MODULE_PATH:PATH=${_CMAKE_DIR}
.if ${OPSYS} != "Darwin"
CMAKE_ARGS+=	-DCMAKE_SKIP_RPATH:BOOL=TRUE
.else
CMAKE_ARGS+=	-DCMAKE_SKIP_RPATH:BOOL=FALSE
CMAKE_ARGS+=	-DCMAKE_INSTALL_NAME_DIR:PATH=${PREFIX}/lib
.endif
.if defined(CMAKE_USE_GNU_INSTALL_DIRS) && empty(CMAKE_USE_GNU_INSTALL_DIRS:M[nN][oO])
CMAKE_ARGS+=	-DCMAKE_INSTALL_LIBDIR:PATH=lib
CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR:PATH=${PKGMANDIR}
.  if defined(INFO_FILES)
CMAKE_ARGS+=	-DCMAKE_INSTALL_INFODIR:PATH=${PKGINFODIR}
.  endif
.  if defined(USE_PKGLOCALEDIR) && empty(USE_PKGLOCALEDIR:M[nN][oO])
CMAKE_ARGS+=	-DCMAKE_INSTALL_LOCALEDIR:PATH=${PKGLOCALEDIR}/locale
.  endif
.endif

.if defined(CMAKE_PREFIX_PATH)
CMAKE_ARGS+=-DCMAKE_PREFIX_PATH:PATH=${CMAKE_PREFIX_PATH:ts;:Q}
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
