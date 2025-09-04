# $NetBSD: inplace.mk,v 1.2 2025/09/04 09:24:55 dkazankov Exp $
#
# Include this file to extract library source into the WRKSRC of
# another package.
#
# Package-settable variables:
#
# CREATE_INPLACE_BUILD_TARGETS
#	List of build targets that need to be created
#	Possible values: static-pic, relocatable.
#
# System-defined variables:
#
# INPLACE_BUILD_TARGETS
#	A list of build targets which can be used as dependency to build
#	inplaced libraries.

post-fetch: fetch-inplace-gnatcoll-core

post-extract: extract-inplace-gnatcoll-core

.PHONY: fetch-inplace-gnatcoll-core
fetch-inplace-gnatcoll-core:
	@${STEP_MSG} Fetching in-place gnatcoll-core
	${RUN}cd ../../devel/ada-gnatcoll-core-25 && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.gnatcoll-core \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			checksum

.PHONY: extract-inplace-gnatcoll-core
extract-inplace-gnatcoll-core:
	@${STEP_MSG} Extracting in-place gnatcoll-core
	${RUN}cd ../../devel/ada-gnatcoll-core-25 && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.gnatcoll-core \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			patch
	${RUN}${MV} ${WRKSRC}/gnatcoll-core-* ${WRKSRC}/gnatcoll-core

.if defined(CREATE_INPLACE_BUILD_TARGETS)

USE_TOOLS+=		gmake sed
.include "../../lang/python/tool.mk"

.  if !empty(CREATE_INPLACE_BUILD_TARGETS:Mrelocatable)

INPLACE_BUILD_TARGETS+=	build-inplace-relocatable-gnatcoll-core

.PHONY: build-inplace-relocatable-gnatcoll-core
build-inplace-relocatable-gnatcoll-core:
	@${STEP_MSG} Building in-place relocatable gnatcoll-core
	${RUN}cd ${WRKSRC}/gnatcoll-core && \
	${CP} minimal/gnatcoll_minimal.gpr.py minimal/gnatcoll_minimal.gpr.py.orig && \
	${SED} -e "s,\"static\"\, \"relocatable\"\, \"static-pic\",\"relocatable\"," \
	    minimal/gnatcoll_minimal.gpr.py.orig \
	    >minimal/gnatcoll_minimal.gpr.py && \
	${CP} core/gnatcoll_core.gpr.py core/gnatcoll_core.gpr.py.orig && \
	${SED} -e "s,\"static\"\, \"relocatable\"\, \"static-pic\",\"relocatable\"," \
	    core/gnatcoll_core.gpr.py.orig \
	    >core/gnatcoll_core.gpr.py && \
	${CP} projects/gnatcoll_projects.gpr.py projects/gnatcoll_projects.gpr.py.orig && \
	${SED} -e "s,\"static\"\, \"relocatable\"\, \"static-pic\",\"relocatable\"," \
	    projects/gnatcoll_projects.gpr.py.orig \
	    >projects/gnatcoll_projects.gpr.py && \
	${PKGSRC_SETENV} ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} PYTHON=${PYTHONBIN:Q} prefix=${BUILDLINK_DIR} BUILD=PROD ENABLE_SHARED=yes \
	    -f Makefile all && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} PYTHON=${PYTHONBIN:Q} prefix=${BUILDLINK_DIR} BUILD=PROD ENABLE_SHARED=yes \
	    -f Makefile install

.  endif

.  if !empty(CREATE_INPLACE_BUILD_TARGETS:Mstatic-pic)

INPLACE_BUILD_TARGETS+=	build-inplace-static-pic-gnatcoll-core

.PHONY: build-inplace-static-pic-gnatcoll-core
build-inplace-static-pic-gnatcoll-core:
	@${STEP_MSG} Building in-place static-pic gnatcoll-core
	${RUN}cd ${WRKSRC}/gnatcoll-core && \
	${CP} minimal/gnatcoll_minimal.gpr.py minimal/gnatcoll_minimal.gpr.py.orig && \
	${SED} -e "s,\"static\"\, \"relocatable\"\, \"static-pic\",\"static-pic\"," \
	    minimal/gnatcoll_minimal.gpr.py.orig \
	    >minimal/gnatcoll_minimal.gpr.py && \
	${CP} core/gnatcoll_core.gpr.py core/gnatcoll_core.gpr.py.orig && \
	${SED} -e "s,\"static\"\, \"relocatable\"\, \"static-pic\",\"static-pic\"," \
	    core/gnatcoll_core.gpr.py.orig \
	    >core/gnatcoll_core.gpr.py && \
	${CP} projects/gnatcoll_projects.gpr.py projects/gnatcoll_projects.gpr.py.orig && \
	${SED} -e "s,\"static\"\, \"relocatable\"\, \"static-pic\",\"static-pic\"," \
	    projects/gnatcoll_projects.gpr.py.orig \
	    >projects/gnatcoll_projects.gpr.py && \
	${PKGSRC_SETENV} ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} PYTHON=${PYTHONBIN:Q} prefix=${BUILDLINK_DIR} BUILD=PROD ENABLE_SHARED=yes \
	    -f Makefile all && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} PYTHON=${PYTHONBIN:Q} prefix=${BUILDLINK_DIR} BUILD=PROD ENABLE_SHARED=yes \
	    -f Makefile install

.  endif

.endif
