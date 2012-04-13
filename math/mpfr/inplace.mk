# $NetBSD: inplace.mk,v 1.1 2012/04/13 11:00:14 hans Exp $
#
# Include this file to extract math/mpfr source into the WRKSRC of
# another package. This is to be used by GCC packages to avoid the
# numerous dependencies math/mpfr has.

post-extract: extract-inplace-mpfr

extract-inplace-mpfr:
	(cd ../../math/mpfr && ${MAKE} WRKDIR=${WRKSRC}/.devel.mpfr EXTRACT_DIR=${WRKSRC} \
		WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' SKIP_DEPENDS=YES fetch patch clean)
	${MV} ${WRKSRC}/mpfr-* ${WRKSRC}/mpfr

