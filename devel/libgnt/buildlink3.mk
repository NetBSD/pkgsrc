# $NetBSD: buildlink3.mk,v 1.19 2026/09/29 06:04:34 wiz Exp $

BUILDLINK_TREE+=	libgnt

.if !defined(LIBGNT_BUILDLINK3_MK)
LIBGNT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnt+=	libgnt>=2.14.0
BUILDLINK_ABI_DEPENDS.libgnt?=	libgnt>=2.14.0nb20
BUILDLINK_PKGSRCDIR.libgnt?=	../../devel/libgnt

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBGNT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnt
