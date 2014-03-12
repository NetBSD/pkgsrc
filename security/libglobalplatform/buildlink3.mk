# $NetBSD: buildlink3.mk,v 1.1 2014/03/12 21:23:11 gdt Exp $

BUILDLINK_TREE+=	libglobalplatform

.if !defined(LIBGLOBALPLATFORM_BUILDLINK3_MK)
LIBGLOBALPLATFORM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libglobalplatform+=	libglobalplatform>=6.0.0
BUILDLINK_PKGSRCDIR.libglobalplatform?=	../../security/libglobalplatform

.include "../../security/pcsc-lite/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# LIBGLOBALPLATFORM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libglobalplatform
