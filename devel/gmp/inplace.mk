# $NetBSD: inplace.mk,v 1.2 2013/01/31 20:30:25 adam Exp $
#
# Include this file to extract devel/gmp source into the WRKSRC of
# another package. This is to be used by GCC packages to avoid the
# numerous dependencies devel/gmp has.

post-extract: extract-inplace-gmp

extract-inplace-gmp:
	(cd ../../devel/gmp && ${MAKE} WRKDIR=${WRKSRC}/.devel.gmp EXTRACT_DIR=${WRKSRC} \
		WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' SKIP_DEPENDS=YES fetch patch clean)
	${MV} ${WRKSRC}/gmp-* ${WRKSRC}/gmp
