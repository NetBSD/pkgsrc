# $NetBSD: inplace.mk,v 1.6 2025/01/06 11:09:03 riastradh Exp $
#
# Include this file to extract math/mpcomplex source into the WRKSRC of
# another package. This is to be used by GCC packages to avoid the numerous
# dependencies math/mpcomplex has.

post-fetch: fetch-inplace-mpcomplex

post-extract: extract-inplace-mpcomplex

.PHONY: fetch-inplace-mpcomplex
fetch-inplace-mpcomplex:
	@${STEP_MSG} Fetching in-place mpcomplex
	${RUN}cd ../../math/mpcomplex && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.mpcomplex \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			checksum

.PHONY: extract-inplace-mpcomplex
extract-inplace-mpcomplex:
	@${STEP_MSG} Extracting in-place mpcomplex
	${RUN}cd ../../math/mpcomplex && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.mpcomplex \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			patch
	${RUN}${MV} ${WRKSRC}/mpc-* ${WRKSRC}/mpc
