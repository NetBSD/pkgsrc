# $NetBSD: buildlink3.mk,v 1.13 2024/11/14 22:19:31 wiz Exp $

BUILDLINK_TREE+=	libgnt

.if !defined(LIBGNT_BUILDLINK3_MK)
LIBGNT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnt+=	libgnt>=2.14.0
BUILDLINK_ABI_DEPENDS.libgnt?=	libgnt>=2.14.0nb14
BUILDLINK_PKGSRCDIR.libgnt?=	../../devel/libgnt

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBGNT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnt
