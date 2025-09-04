# $NetBSD: inplace.mk,v 1.1 2025/09/04 07:55:37 dkazankov Exp $
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

post-fetch: fetch-inplace-adasat

post-extract: extract-inplace-adasat

.PHONY: fetch-inplace-adasat
fetch-inplace-adasat:
	@${STEP_MSG} Fetching in-place adasat
	${RUN}cd ../../math/ada-adasat-25 && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.adasat \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			checksum

.PHONY: extract-inplace-adasat
extract-inplace-adasat:
	@${STEP_MSG} Extracting in-place adasat
	${RUN}cd ../../math/ada-adasat-25 && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.adasat \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			patch
	${RUN}${MV} ${WRKSRC}/AdaSAT-* ${WRKSRC}/adasat

.if defined(CREATE_INPLACE_BUILD_TARGETS)

USE_TOOLS+=		gmake

.if !empty(CREATE_INPLACE_BUILD_TARGETS:Mrelocatable)

INPLACE_BUILD_TARGETS+=	build-inplace-relocatable-adasat

.PHONY: build-inplace-relocatable-adasat
build-inplace-relocatable-adasat:
	@${STEP_MSG} Building in-place relocatable AdaSAT
	${RUN}cd ${WRKSRC}/adasat && \
	${PKGSRC_SETENV} ${MAKE_ENV}  \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} BUILD_MODE=prod LIBRARY_TYPE=relocatable \
	    -f Makefile lib && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} \
	    INSTALL_DIR=${BUILDLINK_DIR} BUILD_MODE=prod LIBRARY_TYPE=relocatable \
	    -f Makefile install-lib

.endif

.if !empty(CREATE_INPLACE_BUILD_TARGETS:Mstatic-pic)

INPLACE_BUILD_TARGETS+=	build-inplace-static-pic-adasat

.PHONY: build-inplace-static-pic-adasat
build-inplace-static-pic-adasat:
	@${STEP_MSG} Building in-place static-pic AdaSAT
	${RUN}cd ${WRKSRC}/adasat && \
	${PKGSRC_SETENV} ${MAKE_ENV}  \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} BUILD_MODE=prod LIBRARY_TYPE=static-pic \
	    -f Makefile lib && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} \
	    INSTALL_DIR=${BUILDLINK_DIR} BUILD_MODE=prod LIBRARY_TYPE=static-pic \
	    -f Makefile install-lib

.endif

.endif
