# $NetBSD: buildlink3.mk,v 1.15 2014/01/01 11:52:02 wiz Exp $

BUILDLINK_TREE+=	opencdk

.if !defined(OPENCDK_BUILDLINK3_MK)
OPENCDK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencdk+=	opencdk>=0.5.4nb1
BUILDLINK_ABI_DEPENDS.opencdk+=	opencdk>=0.6.6nb2
BUILDLINK_PKGSRCDIR.opencdk?=	../../security/opencdk

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.endif # OPENCDK_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencdk
