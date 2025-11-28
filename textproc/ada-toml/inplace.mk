# $NetBSD: inplace.mk,v 1.1 2025/11/28 20:07:22 dkazankov Exp $
#
# Include this file to extract library source into the WRKSRC of
# another package.
#
# Package-settable variables:
#
# CREATE_INPLACE_BUILD_TARGETS
#	List of build targets that need to be created
#	Possible values: static, static-pic, relocatable.
#
# System-defined variables:
#
# INPLACE_BUILD_TARGETS
#	A list of build targets which can be used as dependency to build
#	inplaced libraries.

post-fetch: fetch-inplace-ada-toml

post-extract: extract-inplace-ada-toml

.PHONY: fetch-inplace-ada-toml
fetch-inplace-ada-toml:
	@${STEP_MSG} Fetching in-place ada-toml
	${RUN}cd ../../textproc/ada-toml && \
		${MAKE} WRKDIR=${WRKDIR}/.devel.ada-toml \
			EXTRACT_DIR=${WRKDIR} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			checksum

.PHONY: extract-inplace-ada-toml
extract-inplace-ada-toml:
	@${STEP_MSG} Extracting in-place ada-toml
	${RUN}cd ../../textproc/ada-toml && \
		${MAKE} WRKDIR=${WRKDIR}/.devel.ada-toml \
			EXTRACT_DIR=${WRKDIR} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			patch
	${RUN}${MV} ${WRKDIR}/ada-toml-* ${WRKSRC}/ada-toml

.if defined(CREATE_INPLACE_BUILD_TARGETS)

USE_TOOLS+=		gmake

.  if !empty(CREATE_INPLACE_BUILD_TARGETS:Mstatic-pic)

INPLACE_BUILD_TARGETS+=	build-inplace-static-pic-ada-toml

.PHONY: build-inplace-static-pic-ada-toml
build-inplace-static-pic-ada-toml:
	@${STEP_MSG} Building in-place static-pic ada-toml
	${RUN}cd ${WRKSRC}/ada-toml && \
		${PKGSRC_SETENV} ${MAKE_ENV} \
			${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} prefix=/. \
			-f Makefile build-static-pic && \
		${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
			${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} prefix=/. DESTDIR=${BUILDLINK_DIR} \
			-f Makefile install-static-pic

.  endif

.  if !empty(CREATE_INPLACE_BUILD_TARGETS:Mstatic)

INPLACE_BUILD_TARGETS+=	build-inplace-static-ada-toml

.PHONY: build-inplace-static-ada-toml
build-inplace-static-ada-toml:
	@${STEP_MSG} Building in-place static ada-toml
	${RUN}cd ${WRKSRC}/ada-toml && \
		${PKGSRC_SETENV} ${MAKE_ENV} \
			${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} prefix=/. \
			-f Makefile build-static && \
		${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
			${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} prefix=/. DESTDIR=${BUILDLINK_DIR} \
			-f Makefile install-static

.  endif

.endif
