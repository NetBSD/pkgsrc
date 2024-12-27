# $NetBSD: buildlink3.mk,v 1.51 2024/12/27 08:19:43 wiz Exp $

BUILDLINK_TREE+=	gpsim

.if !defined(GPSIM_BUILDLINK3_MK)
GPSIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpsim+=	gpsim>=20050905
BUILDLINK_ABI_DEPENDS.gpsim+=	gpsim>=20050905nb49
BUILDLINK_PKGSRCDIR.gpsim?=	../../emulators/gpsim-devel

.include "../../x11/gtk2/buildlink3.mk"
.endif # GPSIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpsim
