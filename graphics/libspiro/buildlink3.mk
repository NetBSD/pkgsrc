# $NetBSD: buildlink3.mk,v 1.1 2017/05/04 19:21:35 adam Exp $

BUILDLINK_TREE+=	libspiro

.if !defined(LIBSPIRO_BUILDLINK3_MK)
LIBSPIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libspiro+=	libspiro>=0.5.20150702
BUILDLINK_PKGSRCDIR.libspiro?=		../../graphics/libspiro
.endif	# LIBSPIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libspiro
