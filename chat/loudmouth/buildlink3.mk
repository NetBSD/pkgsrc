# $NetBSD: buildlink3.mk,v 1.28 2026/09/27 11:35:12 tnn Exp $

BUILDLINK_TREE+=	loudmouth

.if !defined(LOUDMOUTH_BUILDLINK3_MK)
LOUDMOUTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.loudmouth+=	loudmouth>=1.0
BUILDLINK_ABI_DEPENDS.loudmouth+=	loudmouth>=1.5.4nb7
BUILDLINK_PKGSRCDIR.loudmouth?=		../../chat/loudmouth

.include "../../devel/glib2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.endif # LOUDMOUTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-loudmouth
