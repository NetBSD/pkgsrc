# $NetBSD: buildlink3.mk,v 1.23 2023/08/14 05:24:08 wiz Exp $

BUILDLINK_TREE+=	glibmm

.if !defined(GLIBMM_BUILDLINK3_MK)
GLIBMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glibmm+=	glibmm>=2.24.2
BUILDLINK_ABI_DEPENDS.glibmm+=	glibmm>=2.66.6nb1
BUILDLINK_PKGSRCDIR.glibmm?=	../../devel/glibmm

USE_CXX_FEATURES+=	regex c++11

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.endif # GLIBMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-glibmm
