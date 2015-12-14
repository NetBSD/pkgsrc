# $NetBSD: buildlink3.mk,v 1.4 2015/12/14 14:07:42 ryoon Exp $

BUILDLINK_TREE+=	libassuan

.if !defined(LIBASSUAN_BUILDLINK3_MK)
LIBASSUAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libassuan+=	libassuan>=2.4.2
BUILDLINK_ABI_DEPENDS.libassuan+=	libassuan>=2.4.2
BUILDLINK_PKGSRCDIR.libassuan?=	../../security/libassuan2

.include "../../security/libgpg-error/buildlink3.mk"
.endif # LIBASSUAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libassuan
