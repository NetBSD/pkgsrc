# $NetBSD: buildlink3.mk,v 1.3 2011/04/22 13:42:47 obache Exp $

BUILDLINK_TREE+=	libassuan

.if !defined(LIBASSUAN_BUILDLINK3_MK)
LIBASSUAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libassuan+=	libassuan>=2.0.0
BUILDLINK_ABI_DEPENDS.libassuan+=	libassuan>=2.0.1nb2
BUILDLINK_PKGSRCDIR.libassuan?=	../../security/libassuan2

.include "../../security/libgpg-error/buildlink3.mk"
.endif # LIBASSUAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libassuan
