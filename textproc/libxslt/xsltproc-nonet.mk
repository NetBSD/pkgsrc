# $NetBSD: xsltproc-nonet.mk,v 1.3 2015/07/09 01:56:44 richard Exp $

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

pre-configure: create-xsltproc-wrapper

# --nonet avoids network connections during builds
# XLSTPROC_PATH allows any necessary files (e.g. dtds) to be found
# locally in the paths provided with the default being '--path .'
create-xsltproc-wrapper:
	${PRINTF} "#! ${SH}\\n\
	${LOCALBASE}/bin/xsltproc --nonet \
	--path ${XSLTPROC_PATH:U.:O:u:ts::Q} \$$*\\n\
	" > ${BUILDLINK_DIR}/bin/xsltproc
	${CHMOD} +x ${BUILDLINK_DIR}/bin/xsltproc
