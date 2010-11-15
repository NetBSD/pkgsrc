# $NetBSD: buildlink3.mk,v 1.4 2010/11/15 22:56:43 abs Exp $

BUILDLINK_TREE+=	libview

.if !defined(LIBVIEW_BUILDLINK3_MK)
LIBVIEW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libview+=	libview>=0.6.4
BUILDLINK_ABI_DEPENDS.libview?=	libview>=0.6.4nb3
BUILDLINK_PKGSRCDIR.libview?=	../../devel/libview

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.endif	# LIBVIEW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libview
