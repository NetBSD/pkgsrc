# $NetBSD: inplace.mk,v 1.3 2013/07/08 20:18:52 jperkin Exp $
#
# Include this file to extract math/mpcomplex source into the WRKSRC of
# another package. This is to be used by GCC packages to avoid the numerous
# dependencies math/mpcomplex has.

post-fetch: fetch-inplace-mpcomplex

post-extract: extract-inplace-mpcomplex

fetch-inplace-mpcomplex:
	(cd ../../math/mpcomplex && ${MAKE} WRKDIR=${WRKSRC}/.devel.mpcomplex EXTRACT_DIR=${WRKSRC} \
		WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' SKIP_DEPENDS=YES checksum clean)

extract-inplace-mpcomplex:
	(cd ../../math/mpcomplex && ${MAKE} WRKDIR=${WRKSRC}/.devel.mpcomplex EXTRACT_DIR=${WRKSRC} \
		WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' SKIP_DEPENDS=YES patch clean)
	${MV} ${WRKSRC}/mpc-* ${WRKSRC}/mpc
