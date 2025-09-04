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

post-fetch: fetch-inplace-libgpr

post-extract: extract-inplace-libgpr

.PHONY: fetch-inplace-libgpr
fetch-inplace-libgpr:
	@${STEP_MSG} Fetching in-place libgpr
	${RUN}cd ../../devel/ada-libgpr-25 && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.libgpr \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			checksum

.PHONY: extract-inplace-libgpr
extract-inplace-libgpr:
	@${STEP_MSG} Extracting in-place libgpr
	${RUN}cd ../../devel/ada-libgpr-25 && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.libgpr \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			patch
	${RUN}${MV} ${WRKSRC}/gprbuild-* ${WRKSRC}/libgpr

.if defined(CREATE_INPLACE_BUILD_TARGETS)

USE_TOOLS+=		gmake

.  if !empty(CREATE_INPLACE_BUILD_TARGETS:Mrelocatable)

INPLACE_BUILD_TARGETS+=	build-inplace-relocatable-libgpr

.PHONY: build-inplace-relocatable-libgpr
build-inplace-relocatable-libgpr:
	@${STEP_MSG} Building in-place relocatable libgpr
	${RUN}cd ${WRKSRC}/libgpr && \
	${PKGSRC_SETENV} ${CONFIGURE_ENV} \
	    ${MAKE_PROGRAM} prefix=${BUILDLINK_DIR} ENABLE_SHARED=yes -f Makefile setup && \
	${PKGSRC_SETENV} ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} \
	    -f Makefile libgpr.build.shared && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} DESTDIR=${BUILDLINK_DIR} \
	    -f Makefile libgpr.install.shared

.  endif

.  if !empty(CREATE_INPLACE_BUILD_TARGETS:Mstatic-pic)

INPLACE_BUILD_TARGETS+=	build-inplace-static-pic-libgpr

.PHONY: build-inplace-static-pic-libgpr
build-inplace-static-pic-libgpr:
	@${STEP_MSG} Building in-place static-pic libgpr
	${RUN}cd ${WRKSRC}/libgpr && \
	${PKGSRC_SETENV} ${CONFIGURE_ENV} \
	    ${MAKE_PROGRAM} prefix=${BUILDLINK_DIR} ENABLE_SHARED=yes -f Makefile setup && \
	${PKGSRC_SETENV} ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} \
	    -f Makefile libgpr.build.static-pic && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} DESTDIR=${BUILDLINK_DIR} \
	    -f Makefile libgpr.install.static-pic

.  endif

.endif
