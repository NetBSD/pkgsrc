# $NetBSD: buildlink3.mk,v 1.20 2021/12/08 16:01:52 adam Exp $

BUILDLINK_TREE+=	glibmm

.if !defined(GLIBMM_BUILDLINK3_MK)
GLIBMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glibmm+=	glibmm>=2.24.2
BUILDLINK_ABI_DEPENDS.glibmm+=	glibmm>=2.66.2
BUILDLINK_PKGSRCDIR.glibmm?=	../../devel/glibmm

GCC_REQD+=	4.9

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.endif # GLIBMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-glibmm
