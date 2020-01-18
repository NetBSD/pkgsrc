# $NetBSD: buildlink3.mk,v 1.4 2020/01/18 21:48:22 jperkin Exp $

BUILDLINK_TREE+=	libglobalplatform

.if !defined(LIBGLOBALPLATFORM_BUILDLINK3_MK)
LIBGLOBALPLATFORM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libglobalplatform+=	libglobalplatform>=6.0.0
BUILDLINK_ABI_DEPENDS.libglobalplatform?=	libglobalplatform>=6.0.0nb2
BUILDLINK_PKGSRCDIR.libglobalplatform?=		../../security/libglobalplatform

.include "../../security/pcsc-lite/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# LIBGLOBALPLATFORM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libglobalplatform
