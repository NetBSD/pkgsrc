# $NetBSD: buildlink3.mk,v 1.7 2026/09/27 11:35:10 tnn Exp $

BUILDLINK_TREE+=	bitlbee

.if !defined(BITLBEE_BUILDLINK3_MK)
BITLBEE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bitlbee+=	bitlbee>=3.6nb1
BUILDLINK_ABI_DEPENDS.bitlbee?=	bitlbee>=3.6nb26
BUILDLINK_PKGSRCDIR.bitlbee?=	../../chat/bitlbee

.include "../../devel/glib2/buildlink3.mk"
.endif	# BITLBEE_BUILDLINK3_MK

BUILDLINK_TREE+=	-bitlbee
