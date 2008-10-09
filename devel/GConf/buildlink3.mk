# $NetBSD: buildlink3.mk,v 1.15 2008/10/09 20:53:48 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GCONF_BUILDLINK3_MK:=	${GCONF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	GConf
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NGConf}
BUILDLINK_PACKAGES+=	GConf
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}GConf

.if !empty(GCONF_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.GConf+=	GConf>=2.8.0.1
BUILDLINK_ABI_DEPENDS.GConf?=	GConf>=2.12.1nb1
BUILDLINK_PKGSRCDIR.GConf?=	../../devel/GConf
.endif	# GCONF_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/xmlcatmgr/buildlink3.mk"

.if !empty(GCONF_BUILDLINK3_MK:M+)
BUILDLINK_TARGETS+=	GConf-buildlink-fake
_GCONF_FAKE=		${BUILDLINK_DIR}/bin/gconftool-2

.PHONY: GConf-buildlink-fake
GConf-buildlink-fake:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${_GCONF_FAKE} ]; then				\
		${ECHO_BUILDLINK_MSG} "Creating ${_GCONF_FAKE}";	\
		${MKDIR} ${_GCONF_FAKE:H};				\
		${ECHO} "#!${SH}" > ${_GCONF_FAKE};			\
		${CHMOD} +x ${_GCONF_FAKE};				\
	fi
.endif	# GCONF_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
