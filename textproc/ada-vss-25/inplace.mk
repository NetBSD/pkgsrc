# $NetBSD: inplace.mk,v 1.2 2025/09/04 09:24:56 dkazankov Exp $
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

post-fetch: fetch-inplace-vss

post-extract: extract-inplace-vss

.PHONY: fetch-inplace-vss
fetch-inplace-vss:
	@${STEP_MSG} Fetching in-place VSS
	${RUN}cd ../../textproc/ada-vss-25 && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.vss \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			checksum

.PHONY: extract-inplace-vss
extract-inplace-vss:
	@${STEP_MSG} Extracting in-place VSS
	${RUN}cd ../../textproc/ada-vss-25 && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.vss \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			patch
	${RUN}${MV} ${WRKSRC}/VSS-* ${WRKSRC}/vss

.if defined(CREATE_INPLACE_BUILD_TARGETS)

USE_TOOLS+=		gmake

.  if !empty(CREATE_INPLACE_BUILD_TARGETS:Mrelocatable)

INPLACE_BUILD_TARGETS+=	build-inplace-relocatable-vss

.PHONY: build-inplace-relocatable-vss
build-inplace-relocatable-vss:
	@${STEP_MSG} Building in-place relocatable VSS
	${RUN}cd ${WRKSRC}/vss && \
	${PKGSRC_SETENV} ${MAKE_ENV}  \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} BUILD_PROFILE=release GPRFLAGS=${GPRBUILD_OPTIONS:Q} \
	    -f Makefile build-libs-relocatable && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} DESTDIR=${BUILDLINK_DIR} PREFIX=/. \
	    -f Makefile install-libs-relocatable

.  endif

.  if !empty(CREATE_INPLACE_BUILD_TARGETS:Mstatic-pic)

INPLACE_BUILD_TARGETS+=	build-inplace-static-pic-vss

.PHONY: build-inplace-static-pic-vss
build-inplace-static-pic-vss:
	@${STEP_MSG} Building in-place static-pic VSS
	${RUN}cd ${WRKSRC}/vss && \
	${PKGSRC_SETENV} ${MAKE_ENV}  \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} BUILD_PROFILE=release GPRFLAGS=${GPRBUILD_OPTIONS:Q} \
	    -f Makefile build-libs-static-pic && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} DESTDIR=${BUILDLINK_DIR} PREFIX=/. \
	    -f Makefile install-libs-static-pic

.  endif

.endif
