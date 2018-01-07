# $NetBSD: buildlink3.mk,v 1.12 2018/01/07 13:04:25 rillig Exp $

BUILDLINK_TREE+=	libmpeg2

.if !defined(LIBMPEG2_BUILDLINK3_MK)
LIBMPEG2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmpeg2+=	libmpeg2>=0.4.0
BUILDLINK_ABI_DEPENDS.libmpeg2+=	libmpeg2>=0.4.0bnb5
BUILDLINK_PKGSRCDIR.libmpeg2?=		../../multimedia/libmpeg2
.endif # LIBMPEG2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmpeg2
