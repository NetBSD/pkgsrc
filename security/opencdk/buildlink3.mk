# $NetBSD: buildlink3.mk,v 1.14 2011/04/22 13:42:48 obache Exp $

BUILDLINK_TREE+=	opencdk

.if !defined(OPENCDK_BUILDLINK3_MK)
OPENCDK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencdk+=	opencdk>=0.5.4nb1
BUILDLINK_ABI_DEPENDS.opencdk+=	opencdk>=0.6.6nb1
BUILDLINK_PKGSRCDIR.opencdk?=	../../security/opencdk

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.endif # OPENCDK_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencdk
