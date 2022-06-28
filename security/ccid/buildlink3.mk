# $NetBSD: buildlink3.mk,v 1.5 2022/06/28 11:35:34 wiz Exp $

BUILDLINK_TREE+=	ccid

.if !defined(CCID_BUILDLINK3_MK)
CCID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ccid+=	ccid>=1.4.0
BUILDLINK_ABI_DEPENDS.ccid?=	ccid>=1.5.0nb1
BUILDLINK_PKGSRCDIR.ccid?=	../../security/ccid

.include "../../security/pcsc-lite/buildlink3.mk"
.endif # CCID_BUILDLINK3_MK

BUILDLINK_TREE+=	-ccid
