# $NetBSD: buildlink3.mk,v 1.1 2014/10/25 19:00:14 prlw1 Exp $

BUILDLINK_TREE+=	libgee0.6

.if !defined(LIBGEE0.6_BUILDLINK3_MK)
LIBGEE0.6_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgee0.6+=	libgee0.6>=0.5.3
BUILDLINK_ABI_DEPENDS.libgee0.6+=	libgee0.6>=0.6.5nb1
BUILDLINK_ABI_DEPENDS.libgee0.6+=	libgee0.6<0.8
BUILDLINK_PKGSRCDIR.libgee0.6?=	../../devel/libgee0.6

.include "../../devel/glib2/buildlink3.mk"
.endif # LIBGEE0.6_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgee0.6
