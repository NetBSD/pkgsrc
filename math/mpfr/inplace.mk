# $NetBSD: inplace.mk,v 1.3 2013/07/08 20:18:52 jperkin Exp $
#
# Include this file to extract math/mpfr source into the WRKSRC of
# another package. This is to be used by GCC packages to avoid the
# numerous dependencies math/mpfr has.

post-fetch: fetch-inplace-mpfr

post-extract: extract-inplace-mpfr

fetch-inplace-mpfr:
	(cd ../../math/mpfr && ${MAKE} WRKDIR=${WRKSRC}/.devel.mpfr EXTRACT_DIR=${WRKSRC} \
		WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' SKIP_DEPENDS=YES checksum clean)

extract-inplace-mpfr:
	(cd ../../math/mpfr && ${MAKE} WRKDIR=${WRKSRC}/.devel.mpfr EXTRACT_DIR=${WRKSRC} \
		WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' SKIP_DEPENDS=YES patch clean)
	${MV} ${WRKSRC}/mpfr-* ${WRKSRC}/mpfr
