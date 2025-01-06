# $NetBSD: inplace.mk,v 1.6 2025/01/06 11:09:03 riastradh Exp $
#
# Include this file to extract math/mpfr source into the WRKSRC of
# another package. This is to be used by GCC packages to avoid the
# numerous dependencies math/mpfr has.

.PHONY: fetch-inplace-mpfr extract-inplace-mpfr
post-fetch: fetch-inplace-mpfr

post-extract: extract-inplace-mpfr

fetch-inplace-mpfr:
	@${STEP_MSG} Fetching in-place mpfr
	${RUN}cd ../../math/mpfr && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.mpfr \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			checksum

extract-inplace-mpfr:
	@${STEP_MSG} Extracting in-place mpfr
	${RUN}cd ../../math/mpfr && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.mpfr \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			patch
	${RUN}${MV} ${WRKSRC}/mpfr-* ${WRKSRC}/mpfr
