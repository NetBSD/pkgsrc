# $NetBSD: buildlink3.mk,v 1.9 2018/01/07 13:04:24 rillig Exp $

BUILDLINK_TREE+=	libdvdplay

.if !defined(LIBDVDPLAY_BUILDLINK3_MK)
LIBDVDPLAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdvdplay+=	libdvdplay>=1.0.1
BUILDLINK_ABI_DEPENDS.libdvdplay+=	libdvdplay>=1.0.1nb3
BUILDLINK_PKGSRCDIR.libdvdplay?=	../../multimedia/libdvdplay

.include "../../multimedia/libdvdread/buildlink3.mk"
.endif # LIBDVDPLAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdvdplay
