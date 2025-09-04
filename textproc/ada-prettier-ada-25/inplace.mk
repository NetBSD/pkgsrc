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

post-fetch: fetch-inplace-prettier-ada

post-extract: extract-inplace-prettier-ada

.PHONY: fetch-inplace-prettier-ada
fetch-inplace-prettier-ada:
	@${STEP_MSG} Fetching in-place prettier-ada
	${RUN}cd ../../textproc/ada-prettier-ada-25 && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.prettier-ada \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			checksum

.PHONY: extract-inplace-prettier-ada
extract-inplace-prettier-ada:
	@${STEP_MSG} Extracting in-place prettier-ada
	${RUN}cd ../../textproc/ada-prettier-ada-25 && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.prettier-ada \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			patch
	${RUN}${MV} ${WRKSRC}/prettier-ada-* ${WRKSRC}/prettier-ada

.if defined(CREATE_INPLACE_BUILD_TARGETS)

USE_TOOLS+=		gmake

.  if !empty(CREATE_INPLACE_BUILD_TARGETS:Mrelocatable)

INPLACE_BUILD_TARGETS+=	build-inplace-relocatable-prettier-ada

.PHONY: build-inplace-relocatable-prettier-ada
build-inplace-relocatable-prettier-ada:
	@${STEP_MSG} Building in-place relocatable prettier-ada
	${RUN}cd ${WRKSRC}/prettier-ada && \
	${PKGSRC_SETENV} ${MAKE_ENV}  \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} LIBRARY_TYPE=relocatable BUILD_MODE=prod \
	    -f Makefile lib && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} \
	    DESTDIR=${BUILDLINK_DIR} PREFIX=${BUILDLINK_DIR} LIBRARY_TYPE=relocatable BUILD_MODE=prod \
	    -f Makefile install

.  endif

.  if !empty(CREATE_INPLACE_BUILD_TARGETS:Mstatic-pic)

INPLACE_BUILD_TARGETS+=	build-inplace-static-pic-prettier-ada

.PHONY: build-inplace-static-pic-prettier-ada
build-inplace-static-pic-prettier-ada:
	@${STEP_MSG} Building in-place static-pic prettier-ada
	${RUN}cd ${WRKSRC}/prettier-ada && \
	${PKGSRC_SETENV} ${MAKE_ENV}  \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} LIBRARY_TYPE=static-pic BUILD_MODE=prod \
	    -f Makefile lib && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} \
	    DESTDIR=${BUILDLINK_DIR} PREFIX=${BUILDLINK_DIR} LIBRARY_TYPE=static-pic BUILD_MODE=prod \
	    -f Makefile install

.  endif

.endif
