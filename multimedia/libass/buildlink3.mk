# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/09 10:24:18 abs Exp $

BUILDLINK_TREE+=	libass

.if !defined(LIBASS_BUILDLINK3_MK)
LIBASS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libass+=	libass>=0.9.12
BUILDLINK_PKGSRCDIR.libass?=	../../multimedia/libass
.endif # LIBASS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libass
