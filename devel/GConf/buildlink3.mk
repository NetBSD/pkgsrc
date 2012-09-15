# $NetBSD: buildlink3.mk,v 1.23 2012/09/15 10:04:04 obache Exp $

BUILDLINK_TREE+=	GConf

.if !defined(GCONF_BUILDLINK3_MK)
GCONF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.GConf+=	GConf>=2.8.0.1
BUILDLINK_ABI_DEPENDS.GConf+=	GConf>=2.32.4nb5
BUILDLINK_PKGSRCDIR.GConf?=	../../devel/GConf

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/xmlcatmgr/buildlink3.mk"

BUILDLINK_TARGETS+=	GConf-buildlink-fake
_GCONF_FAKE=		${BUILDLINK_DIR}/bin/gconftool-2

.PHONY: GConf-buildlink-fake
GConf-buildlink-fake:
	${RUN} \
	if [ ! -f ${_GCONF_FAKE} ]; then				\
		${ECHO_BUILDLINK_MSG} "Creating ${_GCONF_FAKE}";	\
		${MKDIR} ${_GCONF_FAKE:H};				\
		${ECHO} "#!${SH}" > ${_GCONF_FAKE};			\
		${CHMOD} +x ${_GCONF_FAKE};				\
	fi
.endif # GCONF_BUILDLINK3_MK

BUILDLINK_TREE+=	-GConf
