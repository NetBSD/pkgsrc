# $NetBSD: xsltproc-nonet.mk,v 1.2 2015/07/08 10:34:46 richard Exp $

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

pre-configure: create-xsltproc-wrapper

# --nonet avoids network connections during builds
# XLSTPROC_PATH allows any necessary files (e.g. dtds) to be found
# locally in the paths provided with the default being '--path .'
create-xsltproc-wrapper:
	${PRINTF} "#! ${SH}\\n\
	${LOCALBASE}/bin/xsltproc --nonet \
	--path ${XLSTPROC_PATH:U.:O:u:ts::Q} \$$*\\n\
	" > ${BUILDLINK_DIR}/bin/xsltproc
	${CHMOD} +x ${BUILDLINK_DIR}/bin/xsltproc
