# $NetBSD: inplace.mk,v 1.1 2025/09/04 07:53:28 dkazankov Exp $
#
# Include this file to extract library source into the WRKSRC of
# another package.
#
# Package-settable variables:
#
# CREATE_INPLACE_BUILD_TARGETS
#	List of build targets that need to be created
#	Possible values: static-pic, relocatable.
# GNATCOLL_INPLACE_BINDINGS
#	List of bindings
#	Possible values: cpp, gmp, iconv, lzma, openmp, python2, python3,
#	readline, syslog, zlib.
#
# System-defined variables:
#
# INPLACE_BUILD_TARGETS
#	A list of build targets which can be used as dependency to build
#	inplaced libraries.

post-fetch: fetch-inplace-gnatcoll-bindings

post-extract: extract-inplace-gnatcoll-bindings

.PHONY: fetch-inplace-gnatcoll-bindings
fetch-inplace-gnatcoll-bindings:
	@${STEP_MSG} Fetching in-place gnatcoll-bindings
	${RUN}cd ../../devel/ada-gnatcoll-bindings-25 && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.gnatcoll-bindings \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			checksum

.PHONY: extract-inplace-gnatcoll-bindings
extract-inplace-gnatcoll-bindings:
	@${STEP_MSG} Extracting in-place gnatcoll-bindings
	${RUN}cd ../../devel/ada-gnatcoll-bindings-25 && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.gnatcoll-bindings \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			patch
	${RUN}${MV} ${WRKSRC}/gnatcoll-bindings-* ${WRKSRC}/gnatcoll-bindings

.if defined(CREATE_INPLACE_BUILD_TARGETS)

USE_TOOLS+=		gmake sed
.include "../../lang/python/tool.mk"

.include "../../devel/gmp/buildlink3.mk"

USE_GNU_ICONV=	yes
.include "../../converters/libiconv/buildlink3.mk"

.if !empty(CREATE_INPLACE_BUILD_TARGETS:Mrelocatable)

INPLACE_BUILD_TARGETS+=	build-inplace-relocatable-gnatcoll-bindings

.PHONY: build-inplace-relocatable-gnatcoll-bindings
build-inplace-relocatable-gnatcoll-bindings:
	@${STEP_MSG} Building in-place relocatable gnatcoll-bindings
	${RUN}cd ${WRKSRC}/gnatcoll-bindings && \
	${CP} Makefile Makefile.orig && \
	${SED} -e "s,static\,static-pic\,relocatable,relocatable," \
	    Makefile.orig \
	    >Makefile && \
	${PKGSRC_SETENV} ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} PYTHON=${PYTHONBIN:Q} \
		BINDINGS='gmp iconv' prefix=${BUILDLINK_DIR} BUILD=PROD ENABLE_SHARED=yes \
		-f Makefile all && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} PYTHON=${PYTHONBIN:Q} \
		BINDINGS='gmp iconv' DESTDIR=${BUILDLINK_DIR} prefix=${BUILDLINK_DIR} BUILD=PROD ENABLE_SHARED=yes \
		-f Makefile install

.endif

.if !empty(CREATE_INPLACE_BUILD_TARGETS:Mstatic-pic)

INPLACE_BUILD_TARGETS+=	build-inplace-static-pic-gnatcoll-bindings

.PHONY: build-inplace-static-pic-gnatcoll-bindings
build-inplace-static-pic-gnatcoll-bindings:
	@${STEP_MSG} Building in-place static-pic gnatcoll-bindings
	${RUN}cd ${WRKSRC}/gnatcoll-bindings && \
	${CP} Makefile Makefile.orig && \
	${SED} -e "s,static\,static-pic\,relocatable,static-pic," \
	    Makefile.orig \
	    >Makefile && \
	${PKGSRC_SETENV} ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} PYTHON=${PYTHONBIN:Q} \
		BINDINGS=${GNATCOLL_INPLACE_BINDINGS:Q} \
		prefix=${BUILDLINK_DIR} BUILD=PROD ENABLE_SHARED=yes \
		-f Makefile all && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} PYTHON=${PYTHONBIN:Q} \
		BINDINGS=${GNATCOLL_INPLACE_BINDINGS:Q} DESTDIR=${BUILDLINK_DIR} \
		prefix=${BUILDLINK_DIR} BUILD=PROD ENABLE_SHARED=yes \
		-f Makefile install

.endif

.endif
