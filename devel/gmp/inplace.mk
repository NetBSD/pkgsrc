# $NetBSD: inplace.mk,v 1.9 2025/01/06 11:09:03 riastradh Exp $
#
# Include this file to extract devel/gmp source into the WRKSRC of
# another package. This is to be used by GCC packages to avoid the
# numerous dependencies devel/gmp has.

post-fetch: fetch-inplace-gmp

post-extract: extract-inplace-gmp

.PHONY: fetch-inplace-gmp
fetch-inplace-gmp:
	@${STEP_MSG} Fetching in-place gmp
	${RUN}cd ../../devel/gmp && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.gmp \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME:C/a$$//}' \
			SKIP_DEPENDS=YES \
			checksum

.PHONY: extract-inplace-gmp
extract-inplace-gmp:
	@${STEP_MSG} Extracting in-place gmp
	${RUN}cd ../../devel/gmp && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.gmp \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME:C/a$$//}' \
			SKIP_DEPENDS=YES \
			patch
	${RUN}${MV} ${WRKSRC}/gmp-* ${WRKSRC}/gmp

USE_TOOLS+=	bzcat tar
