# $NetBSD: buildlink3.mk,v 1.15 2026/09/29 06:05:28 wiz Exp $

BUILDLINK_TREE+=	libmemphis02

.if !defined(LIBMEMPHIS02_BUILDLINK3_MK)
LIBMEMPHIS02_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmemphis02+=	libmemphis02>=0.2.3
BUILDLINK_ABI_DEPENDS.libmemphis02?=	libmemphis02>=0.2.3nb20
BUILDLINK_PKGSRCDIR.libmemphis02?=	../../geography/libmemphis02

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.endif	# LIBMEMPHIS02_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmemphis02
