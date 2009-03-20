# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:55 joerg Exp $

BUILDLINK_TREE+=	libspf2

.if !defined(LIBSPF2_BUILDLINK3_MK)
LIBSPF2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libspf2+=	libspf2>=1.2.5
BUILDLINK_PKGSRCDIR.libspf2?=	../../mail/libspf2
.endif # LIBSPF2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libspf2
