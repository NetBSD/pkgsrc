# $NetBSD: buildlink3.mk,v 1.11 2024/10/20 14:03:33 wiz Exp $

BUILDLINK_TREE+=	atkmm

.if !defined(ATKMM_BUILDLINK3_MK)
ATKMM_BUILDLINK3_MK:=

GCC_REQD+=	4.9

BUILDLINK_API_DEPENDS.atkmm+=	atkmm>=2.22.1
BUILDLINK_ABI_DEPENDS.atkmm+=	atkmm>=2.28.4nb1
BUILDLINK_PKGSRCDIR.atkmm?=	../../devel/atkmm

.include "../../devel/at-spi2-core/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.endif	# ATKMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-atkmm
