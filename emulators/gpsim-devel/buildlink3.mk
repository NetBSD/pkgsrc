# $NetBSD: buildlink3.mk,v 1.48 2024/04/07 07:33:57 wiz Exp $

BUILDLINK_TREE+=	gpsim

.if !defined(GPSIM_BUILDLINK3_MK)
GPSIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpsim+=	gpsim>=20050905
BUILDLINK_ABI_DEPENDS.gpsim+=	gpsim>=20050905nb46
BUILDLINK_PKGSRCDIR.gpsim?=	../../emulators/gpsim-devel

.include "../../x11/gtk2/buildlink3.mk"
.endif # GPSIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpsim
