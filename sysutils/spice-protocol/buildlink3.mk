# $NetBSD: buildlink3.mk,v 1.2 2021/04/21 16:51:40 pho Exp $

BUILDLINK_TREE+=	spice-protocol

.if !defined(SPICE_PROTOCOL_BUILDLINK3_MK)
SPICE_PROTOCOL_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.spice-protocol?=	build

BUILDLINK_API_DEPENDS.spice-protocol+=	spice-protocol>=0.12.5
BUILDLINK_PKGSRCDIR.spice-protocol?=	../../sysutils/spice-protocol

# spice/enums.h uses __attribute__(__deprecated__) on enums, which is
# only available on GCC 6 or later.
GCC_REQD+=	6

.endif	# SPICE_PROTOCOL_BUILDLINK3_MK

BUILDLINK_TREE+=	-spice-protocol
