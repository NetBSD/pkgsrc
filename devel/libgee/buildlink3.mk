# $NetBSD: buildlink3.mk,v 1.9 2012/12/08 23:22:41 wiz Exp $

BUILDLINK_TREE+=	libgee

.if !defined(LIBGEE_BUILDLINK3_MK)
LIBGEE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgee+=	libgee>=0.5.3
BUILDLINK_ABI_DEPENDS.libgee+=	libgee>=0.6.5nb1
BUILDLINK_ABI_DEPENDS.libgee+=	libgee<0.8
BUILDLINK_PKGSRCDIR.libgee?=	../../devel/libgee

.include "../../devel/glib2/buildlink3.mk"
.endif # LIBGEE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgee
