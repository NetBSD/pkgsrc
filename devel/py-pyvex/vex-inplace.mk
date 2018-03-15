# $NetBSD: vex-inplace.mk,v 1.1 2018/03/15 02:49:25 khorben Exp $
#
# Include this file to extract VEX source into the WRKSRC of
# another package. This is used by angr to build VEX in place.

post-fetch: fetch-inplace-vex

post-extract: extract-inplace-vex

.PHONY: fetch-inplace-vex
fetch-inplace-vex:
	(${MAKE} -f vex.mk WRKDIR=${WRKSRC}/.devel.vex EXTRACT_DIR=${WRKSRC} \
		WRKSRC='$${EXTRACT_DIR}/$${DISTNAME:C/a$$//}' SKIP_DEPENDS=YES checksum)

.PHONY: extract-inplace-vex
extract-inplace-vex:
	(${MAKE} -f vex.mk WRKDIR=${WRKSRC}/.devel.vex EXTRACT_DIR=${WRKSRC} \
		WRKSRC='$${EXTRACT_DIR}/$${DISTNAME:C/a$$//}' SKIP_DEPENDS=YES extract)
	${MV} ${WRKSRC}/vex-* ${WRKSRC}/vex
