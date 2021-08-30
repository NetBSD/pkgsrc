# $NetBSD: inplace.mk,v 1.1 2021/08/30 11:53:45 micha Exp $
#
# Include this file to extract math/isl source into the WRKSRC of
# another package. This is to be used by GCC packages to avoid the
# numerous dependencies math/isl has.

.PHONY: fetch-inplace-isl extract-inplace-isl
post-fetch: fetch-inplace-isl

post-extract: extract-inplace-isl

fetch-inplace-isl:
	(cd ../../math/isl && ${MAKE} WRKDIR=${WRKSRC}/.devel.isl EXTRACT_DIR=${WRKSRC} \
		WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' SKIP_DEPENDS=YES checksum)

extract-inplace-isl:
	(cd ../../math/isl && ${MAKE} WRKDIR=${WRKSRC}/.devel.isl EXTRACT_DIR=${WRKSRC} \
		WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' SKIP_DEPENDS=YES patch)
	${MV} ${WRKSRC}/isl-* ${WRKSRC}/isl
