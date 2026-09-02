# $NetBSD: buildlink3.mk,v 1.3 2026/09/02 19:01:38 wiz Exp $

BUILDLINK_TREE+=	libportal

.if !defined(LIBPORTAL_BUILDLINK3_MK)
LIBPORTAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libportal+=	libportal>=0.9.1
BUILDLINK_ABI_DEPENDS.libportal?=		libportal>=0.9.1nb2
BUILDLINK_PKGSRCDIR.libportal?=		../../devel/libportal

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBPORTAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libportal
