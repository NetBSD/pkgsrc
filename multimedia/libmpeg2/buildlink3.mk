# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:25:04 joerg Exp $

BUILDLINK_TREE+=	libmpeg2

.if !defined(LIBMPEG2_BUILDLINK3_MK)
LIBMPEG2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmpeg2+=	libmpeg2>=0.4.0
BUILDLINK_ABI_DEPENDS.libmpeg2+=	libmpeg2>=0.4.0bnb5
BUILDLINK_PKGSRCDIR.libmpeg2?=	../../multimedia/libmpeg2
.endif # LIBMPEG2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmpeg2
