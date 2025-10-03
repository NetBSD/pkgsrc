# $NetBSD: inplace.mk,v 1.1 2025/10/03 11:47:58 dkazankov Exp $
#
# Include this file to extract library source into the WRKSRC of
# another package.
#

post-fetch: fetch-inplace-templates-parser

post-extract: extract-inplace-templates-parser

.PHONY: fetch-inplace-templates-parser
fetch-inplace-templates-parser:
	@${STEP_MSG} Fetching in-place templates-parser
	${RUN}cd ../../textproc/ada-templates-parser-25 && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.templates-parser \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			checksum

.PHONY: extract-inplace-templates-parser
extract-inplace-templates-parser:
	@${STEP_MSG} Extracting in-place templates-parser
	${RUN}cd ../../textproc/ada-templates-parser-25 && \
		${MAKE} WRKDIR=${WRKSRC}/.devel.templates-parser \
			EXTRACT_DIR=${WRKSRC} \
			WRKSRC='$${EXTRACT_DIR}/$${DISTNAME}' \
			SKIP_DEPENDS=YES \
			patch
	${RUN}${MV} ${WRKSRC}/templates-parser-*/* ${WRKSRC}/templates_parser/
