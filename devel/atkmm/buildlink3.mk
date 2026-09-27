# $NetBSD: buildlink3.mk,v 1.15 2026/09/27 11:35:26 tnn Exp $

BUILDLINK_TREE+=	atkmm

.if !defined(ATKMM_BUILDLINK3_MK)
ATKMM_BUILDLINK3_MK:=

GCC_REQD+=	4.9

BUILDLINK_API_DEPENDS.atkmm+=	atkmm>=2.22.1
BUILDLINK_ABI_DEPENDS.atkmm+=	atkmm>=2.28.5nb2
BUILDLINK_PKGSRCDIR.atkmm?=	../../devel/atkmm

.include "../../devel/at-spi2-core/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.endif	# ATKMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-atkmm
