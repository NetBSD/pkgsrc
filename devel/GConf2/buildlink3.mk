# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 00:53:57 xtraeme Exp $
#
# This Makefile fragment is included by packages that use GConf2.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GCONF2_BUILDLINK3_MK:=	${GCONF2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	GConf2
.endif

.if !empty(GCONF2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			GConf2
BUILDLINK_DEPENDS.GConf2+=		GConf2>=2.4.0.1
BUILDLINK_PKGSRCDIR.GConf2?=		../../devel/GConf2

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/xmlcatmgr/buildlink3.mk"

BUILDLINK_TARGETS+=	GConf2-buildlink-fake

_GCONF2_FAKE=		${BUILDLINK_DIR}/bin/gconftool-2

GConf2-buildlink-fake:
	${_PKG_SILENT}${_PKG_DEBUG}					\
		if [ ! -f ${_GCONF2_FAKE} ]; then			\
		${ECHO_BUILDLINK_MSG} "Creating ${_GCONF2_FAKE}";	\
		${MKDIR} ${_GCONF2_FAKE:H};				\
		${ECHO} "#!${SH}" > ${_GCONF2_FAKE};			\
		${CHMOD} +x ${_GCONF2_FAKE};				\
	fi

.endif # GCONF2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
