# $NetBSD: buildlink3.mk,v 1.35 2025/02/12 06:45:23 ryoon Exp $

BUILDLINK_TREE+=	libkeduvocdocument

.if !defined(LIBKEDUVOCDOCUMENT_BUILDLINK3_MK)
LIBKEDUVOCDOCUMENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkeduvocdocument+=	libkeduvocdocument>=19.08.3
BUILDLINK_ABI_DEPENDS.libkeduvocdocument?=	libkeduvocdocument>=23.08.4nb7
BUILDLINK_PKGSRCDIR.libkeduvocdocument?=	../../misc/libkeduvocdocument

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKEDUVOCDOCUMENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkeduvocdocument
