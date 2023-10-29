# $NetBSD: buildlink3.mk,v 1.1 2023/10/29 13:05:10 rhialto Exp $

BUILDLINK_TREE+=	libsidplayfp

.if !defined(LIBSIDPLAYFP_BUILDLINK3_MK)
LIBSIDPLAYFP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsidplayfp+=	libsidplayfp>=2.5.0
BUILDLINK_ABI_DEPENDS.libsidplayfp+=	libsidplayfp>=2.5.0
BUILDLINK_PKGSRCDIR.libsidplayfp?=	../../audio/libsidplayfp

.endif # LIBSIDPLAYFP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsidplayfp
