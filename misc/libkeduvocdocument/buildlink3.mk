# $NetBSD: buildlink3.mk,v 1.38 2025/10/23 20:38:26 wiz Exp $

BUILDLINK_TREE+=	libkeduvocdocument

.if !defined(LIBKEDUVOCDOCUMENT_BUILDLINK3_MK)
LIBKEDUVOCDOCUMENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkeduvocdocument+=	libkeduvocdocument>=19.08.3
BUILDLINK_ABI_DEPENDS.libkeduvocdocument?=	libkeduvocdocument>=23.08.4nb10
BUILDLINK_PKGSRCDIR.libkeduvocdocument?=	../../misc/libkeduvocdocument

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKEDUVOCDOCUMENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkeduvocdocument
