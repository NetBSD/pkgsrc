# $NetBSD: xsltproc-nonet.mk,v 1.5 2023/06/06 12:42:25 riastradh Exp $

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

pre-configure: create-xsltproc-wrapper

# --nonet avoids network connections during builds
# XLSTPROC_PATH allows any necessary files (e.g. dtds) to be found
# locally in the paths provided with the default being '--path .'
.PHONY: create-xsltproc-wrapper
create-xsltproc-wrapper:
	${PRINTF} "#! ${SH}\\n\
	${PREFIX}/bin/xsltproc --nonet \
	--path ${XSLTPROC_PATH:U.:O:u:ts::Q} \$$*\\n\
	" > ${BUILDLINK_DIR}/bin/xsltproc
	${CHMOD} +x ${BUILDLINK_DIR}/bin/xsltproc
