# $NetBSD: buildlink3.mk,v 1.4 2026/09/27 11:35:43 tnn Exp $

BUILDLINK_TREE+=	libportal

.if !defined(LIBPORTAL_BUILDLINK3_MK)
LIBPORTAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libportal+=	libportal>=0.9.1
BUILDLINK_ABI_DEPENDS.libportal?=		libportal>=0.9.1nb3
BUILDLINK_PKGSRCDIR.libportal?=		../../devel/libportal

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBPORTAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libportal
