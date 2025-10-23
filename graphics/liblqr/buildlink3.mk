# $NetBSD: buildlink3.mk,v 1.10 2025/10/23 20:37:38 wiz Exp $

BUILDLINK_TREE+=	liblqr

.if !defined(LIBLQR_BUILDLINK3_MK)
LIBLQR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblqr+=	liblqr>=0.4.1
BUILDLINK_ABI_DEPENDS.liblqr+=	liblqr>=0.4.3nb1
BUILDLINK_PKGSRCDIR.liblqr?=	../../graphics/liblqr

.include "../../devel/glib2/buildlink3.mk"
.endif # LIBLQR_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblqr
