# $NetBSD: buildlink3.mk,v 1.4 2020/03/08 16:47:45 wiz Exp $

BUILDLINK_TREE+=	libmemphis02

.if !defined(LIBMEMPHIS02_BUILDLINK3_MK)
LIBMEMPHIS02_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmemphis02+=	libmemphis02>=0.2.3
BUILDLINK_ABI_DEPENDS.libmemphis02?=	libmemphis02>=0.2.3nb4
BUILDLINK_PKGSRCDIR.libmemphis02?=	../../geography/libmemphis02

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.endif	# LIBMEMPHIS02_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmemphis02
