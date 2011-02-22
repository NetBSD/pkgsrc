# $NetBSD: buildlink3.mk,v 1.2 2011/02/22 13:33:22 sborrill Exp $

BUILDLINK_TREE+=	netbsd-iscsi-lib

.if !defined(NETBSD_ISCSI_LIB_BUILDLINK3_MK)
NETBSD_ISCSI_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.netbsd-iscsi-lib+=	netbsd-iscsi-lib>=20110222
BUILDLINK_ABI_DEPENDS.netbsd-iscsi-lib+=	netbsd-iscsi-lib>=20110222
BUILDLINK_PKGSRCDIR.netbsd-iscsi-lib?=	../../devel/netbsd-iscsi-lib
.endif # NETBSD_ISCSI_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-netbsd-iscsi-lib
