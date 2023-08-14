# $NetBSD: buildlink3.mk,v 1.4 2023/08/14 05:23:53 wiz Exp $

BUILDLINK_TREE+=	bitlbee

.if !defined(BITLBEE_BUILDLINK3_MK)
BITLBEE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bitlbee+=	bitlbee>=3.6nb1
BUILDLINK_ABI_DEPENDS.bitlbee?=	bitlbee>=3.6nb11
BUILDLINK_PKGSRCDIR.bitlbee?=	../../chat/bitlbee

.include "../../devel/glib2/buildlink3.mk"
.endif	# BITLBEE_BUILDLINK3_MK

BUILDLINK_TREE+=	-bitlbee
