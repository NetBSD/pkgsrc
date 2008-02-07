# $NetBSD: cmake.mk,v 1.3 2008/02/07 21:36:13 rillig Exp $

_CMAKE_DIR=	${BUILDLINK_DIR}/cmake-Modules

CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX}
CMAKE_ARGS+=	-DCMAKE_MODULE_PATH:PATH=${_CMAKE_DIR}

CMAKE_MODULE_PATH_OVERRIDE+=	CMakeLists.txt

######################################################################
### configure-cmake-override (PRIVATE)
######################################################################
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

do-configure-pre-hook: cmake-copy-module-tree

.PHONY: cmake-copy-module-tree
cmake-copy-module-tree:
	${RUN} cd ${PKGSRCDIR}/mk; ${CP} -R cmake-Modules ${_CMAKE_DIR}

######################################################################
### cmake-dependencies-rewrite (PRIVATE)
######################################################################
### The cmake function export_library_dependencies() writes out
### library dependency info to a file and this may contain buildlink
### paths.
### cmake-dependencies-rewrite modifies any such files, listed in
### ${CMAKE_DEPENDENCIES_REWRITE} (relative to ${WRKSRC}) to have the
### real dependencies
###

do-configure-post-hook: cmake-dependencies-rewrite

.PHONY: cmake-dependencies-rewrite
cmake-dependencies-rewrite:
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
