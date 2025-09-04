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

post-fetch: fetch-inplace-xmlada

post-extract: extract-inplace-xmlada

.PHONY: fetch-inplace-xmlada
fetch-inplace-xmlada:
	@${STEP_MSG} Fetching in-place xmlada
	${RUN}cd ../../textproc/ada-xmlada-25 && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.xmlada \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			checksum

.PHONY: extract-inplace-xmlada
extract-inplace-xmlada:
	@${STEP_MSG} Extracting in-place xmlada
	${RUN}cd ../../textproc/ada-xmlada-25 && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.xmlada \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			patch
	${RUN}${MV} ${WRKSRC}/xmlada-* ${WRKSRC}/xmlada

.if defined(CREATE_INPLACE_BUILD_TARGETS)

USE_TOOLS+=		gmake

.  if !empty(CREATE_INPLACE_BUILD_TARGETS:Mrelocatable)

INPLACE_BUILD_TARGETS+=	build-inplace-relocatable-xmlada

.PHONY: build-inplace-relocatable-xmlada
build-inplace-relocatable-xmlada:
	@${STEP_MSG} Building in-place relocatable xmlada
	${RUN}cd ${WRKSRC}/xmlada && \
		${PKGSRC_SETENV} ${CONFIGURE_ENV} \
			${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS} \
			${CONFIGURE_SCRIPT} --prefix=/. --enable-shared && \
		${PKGSRC_SETENV} ${MAKE_ENV} \
			${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} \
			-f Makefile relocatable && \
		${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
			${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} DESTDIR=${BUILDLINK_DIR} \
			-f Makefile install-relocatable

.  endif

.  if !empty(CREATE_INPLACE_BUILD_TARGETS:Mstatic-pic)

INPLACE_BUILD_TARGETS+=	build-inplace-static-pic-xmlada

.PHONY: build-inplace-static-pic-xmlada
build-inplace-static-pic-xmlada:
	@${STEP_MSG} Building in-place static-pic xmlada
	${RUN}cd ${WRKSRC}/xmlada && \
		${PKGSRC_SETENV} ${CONFIGURE_ENV} \
			${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS} \
			${CONFIGURE_SCRIPT} --prefix=/. --enable-shared && \
		${PKGSRC_SETENV} ${MAKE_ENV} \
			${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} \
			-f Makefile static-pic && \
		${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
			${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} DESTDIR=${BUILDLINK_DIR} \
			-f Makefile install-static-pic

.  endif

.endif
