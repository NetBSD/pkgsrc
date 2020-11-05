# $NetBSD: buildlink3.mk,v 1.11 2020/11/05 09:07:02 ryoon Exp $

BUILDLINK_TREE+=	ogle

.if !defined(OGLE_BUILDLINK3_MK)
OGLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ogle+=	ogle>=0.9.2
BUILDLINK_ABI_DEPENDS.ogle+=	ogle>=0.9.2nb11
BUILDLINK_PKGSRCDIR.ogle?=	../../multimedia/ogle

.include "../../textproc/libxml2/buildlink3.mk"
.endif # OGLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ogle
