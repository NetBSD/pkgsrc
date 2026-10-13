# $NetBSD: buildlink3.mk,v 1.7 2026/10/13 17:55:49 gdt Exp $

BUILDLINK_TREE+=	libctl

.if !defined(LIBCTL_BUILDLINK3_MK)
LIBCTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libctl+=	libctl>=4.7.1
BUILDLINK_ABI_DEPENDS.libctl?=	libctl>=4.7.1
BUILDLINK_PKGSRCDIR.libctl?=	../../devel/libctl

.include "../../lang/guile30/buildlink3.mk"
.endif	# LIBCTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libctl
