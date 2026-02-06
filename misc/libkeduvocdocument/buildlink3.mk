# $NetBSD: buildlink3.mk,v 1.42 2026/02/06 10:05:22 wiz Exp $

BUILDLINK_TREE+=	libkeduvocdocument

.if !defined(LIBKEDUVOCDOCUMENT_BUILDLINK3_MK)
LIBKEDUVOCDOCUMENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkeduvocdocument+=	libkeduvocdocument>=25.08.2
BUILDLINK_ABI_DEPENDS.libkeduvocdocument?=	libkeduvocdocument>=25.08.3nb3
BUILDLINK_PKGSRCDIR.libkeduvocdocument?=	../../misc/libkeduvocdocument

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKEDUVOCDOCUMENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkeduvocdocument
