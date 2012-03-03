# $NetBSD: buildlink3.mk,v 1.4 2012/03/03 00:12:28 wiz Exp $

BUILDLINK_TREE+=	atkmm

.if !defined(ATKMM_BUILDLINK3_MK)
ATKMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.atkmm+=	atkmm>=2.22.1
BUILDLINK_ABI_DEPENDS.atkmm?=	atkmm>=2.22.6nb2
BUILDLINK_PKGSRCDIR.atkmm?=	../../devel/atkmm

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.endif	# ATKMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-atkmm
