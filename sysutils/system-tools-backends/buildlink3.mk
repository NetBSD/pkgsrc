# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/11/15 18:28:56 jmcneill Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
SYSTEM_TOOLS_BACKENDS_BUILDLINK3_MK:=	${SYSTEM_TOOLS_BACKENDS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	system-tools-backends
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsystem-tools-backends}
BUILDLINK_PACKAGES+=	system-tools-backends
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}system-tools-backends

.if ${SYSTEM_TOOLS_BACKENDS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.system-tools-backends+=	system-tools-backends>=2.6.0
BUILDLINK_PKGSRCDIR.system-tools-backends?=	../../sysutils/system-tools-backends
.endif	# SYSTEM_TOOLS_BACKENDS_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
