# $NetBSD: buildlink3.mk,v 1.17.12.1 2019/09/20 19:23:33 bsiegert Exp $

BUILDLINK_TREE+=	glibmm

.if !defined(GLIBMM_BUILDLINK3_MK)
GLIBMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glibmm+=	glibmm>=2.24.2
BUILDLINK_ABI_DEPENDS.glibmm+=	glibmm>=2.32.1nb1
BUILDLINK_PKGSRCDIR.glibmm?=	../../devel/glibmm

GCC_REQD+=	4.9

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.endif # GLIBMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-glibmm
