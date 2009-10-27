# $NetBSD: xsltproc-nonet.mk,v 1.1 2009/10/27 14:37:13 drochner Exp $

pre-configure: create-xsltproc-wrapper

create-xsltproc-wrapper:
	${PRINTF} "#! ${SH}\\n\
	  ${LOCALBASE}/bin/xsltproc --nonet \$$*\\n\
	" > ${BUILDLINK_DIR}/bin/xsltproc
	${CHMOD} +x ${BUILDLINK_DIR}/bin/xsltproc
