# $NetBSD: buildlink3.mk,v 1.4 2004/04/01 18:17:29 jmmv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GCONF2_BUILDLINK3_MK:=	${GCONF2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	GConf2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NGConf2}
BUILDLINK_PACKAGES+=	GConf2

.if !empty(GCONF2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.GConf2+=	GConf2>=2.6.0
BUILDLINK_PKGSRCDIR.GConf2?=	../../devel/GConf2
.endif	# GCONF2_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/xmlcatmgr/buildlink3.mk"

.if !empty(GCONF2_BUILDLINK3_MK:M+)
BUILDLINK_TARGETS+=	GConf2-buildlink-fake
_GCONF2_FAKE=		${BUILDLINK_DIR}/bin/gconftool-2

GConf2-buildlink-fake:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${_GCONF2_FAKE} ]; then				\
		${ECHO_BUILDLINK_MSG} "Creating ${_GCONF2_FAKE}";	\
		${MKDIR} ${_GCONF2_FAKE:H};				\
		${ECHO} "#!${SH}" > ${_GCONF2_FAKE};			\
		${CHMOD} +x ${_GCONF2_FAKE};				\
	fi
.endif	# GCONF2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
