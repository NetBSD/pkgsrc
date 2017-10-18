# $NetBSD: inplace.mk,v 1.7 2017/10/18 11:15:39 joerg Exp $
#
# Include this file to extract devel/gmp source into the WRKSRC of
# another package. This is to be used by GCC packages to avoid the
# numerous dependencies devel/gmp has.

post-fetch: fetch-inplace-gmp

post-extract: extract-inplace-gmp

fetch-inplace-gmp:
	(cd ../../devel/gmp && ${MAKE} WRKDIR=${WRKSRC}/.devel.gmp EXTRACT_DIR=${WRKSRC} \
		WRKSRC='$${EXTRACT_DIR}/$${DISTNAME:C/a$$//}' SKIP_DEPENDS=YES checksum)

extract-inplace-gmp:
	(cd ../../devel/gmp && ${MAKE} WRKDIR=${WRKSRC}/.devel.gmp EXTRACT_DIR=${WRKSRC} \
		WRKSRC='$${EXTRACT_DIR}/$${DISTNAME:C/a$$//}' SKIP_DEPENDS=YES patch)
	${MV} ${WRKSRC}/gmp-* ${WRKSRC}/gmp

USE_TOOLS+=	bzcat tar
