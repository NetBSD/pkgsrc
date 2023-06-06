# $NetBSD: buildlink3.mk,v 1.1 2023/06/06 09:56:08 bouyer Exp $

BUILDLINK_TREE+=	ng-spice-shared

.if !defined(NG_SPICE_SHARED_BUILDLINK3_MK)
NG_SPICE_SHARED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ng-spice-shared+=	ng-spice-shared>=40
BUILDLINK_PKGSRCDIR.ng-spice-shared?=		../../cad/ng-spice-shared

.include "../../math/fftw/buildlink3.mk"
.endif	# NG_SPICE_SHARED_BUILDLINK3_MK

BUILDLINK_TREE+=	-ng-spice-shared
