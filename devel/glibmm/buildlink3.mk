# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:24:14 joerg Exp $

BUILDLINK_TREE+=	glibmm

.if !defined(GLIBMM_BUILDLINK3_MK)
GLIBMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glibmm+=	glibmm>=2.6.1
BUILDLINK_ABI_DEPENDS.glibmm+=	glibmm>=2.8.3nb1
BUILDLINK_PKGSRCDIR.glibmm?=	../../devel/glibmm

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.endif # GLIBMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-glibmm
