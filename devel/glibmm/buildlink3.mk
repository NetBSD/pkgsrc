# $NetBSD: buildlink3.mk,v 1.15 2012/09/15 10:04:10 obache Exp $

BUILDLINK_TREE+=	glibmm

.if !defined(GLIBMM_BUILDLINK3_MK)
GLIBMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glibmm+=	glibmm>=2.24.2
BUILDLINK_ABI_DEPENDS.glibmm+=	glibmm>=2.32.1nb1
BUILDLINK_PKGSRCDIR.glibmm?=	../../devel/glibmm

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.endif # GLIBMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-glibmm
