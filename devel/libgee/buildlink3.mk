# $NetBSD: buildlink3.mk,v 1.14 2026/09/02 19:01:36 wiz Exp $

BUILDLINK_TREE+=	libgee

.if !defined(LIBGEE_BUILDLINK3_MK)
LIBGEE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgee+=	libgee>=0.8.2
BUILDLINK_ABI_DEPENDS.libgee+=	libgee>=0.20.8nb1
BUILDLINK_PKGSRCDIR.libgee?=	../../devel/libgee

.include "../../devel/glib2/buildlink3.mk"
.endif # LIBGEE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgee
