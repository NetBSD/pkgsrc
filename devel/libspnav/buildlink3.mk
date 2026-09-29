# $NetBSD: buildlink3.mk,v 1.1 2026/09/29 16:06:19 bouyer Exp $

BUILDLINK_TREE+=	libspnav

.if !defined(LIBSPNAV_BUILDLINK3_MK)
LIBSPNAV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libspnav+=	libspnav>=1.2
BUILDLINK_PKGSRCDIR.libspnav?=		../../devel/libspnav

.include "../../x11/libX11/buildlink3.mk"
.endif	# LIBSPNAV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libspnav
