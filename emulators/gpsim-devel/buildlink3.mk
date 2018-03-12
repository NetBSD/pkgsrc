# $NetBSD: buildlink3.mk,v 1.35 2018/03/12 11:15:32 wiz Exp $

BUILDLINK_TREE+=	gpsim

.if !defined(GPSIM_BUILDLINK3_MK)
GPSIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpsim+=	gpsim>=20050905
BUILDLINK_ABI_DEPENDS.gpsim+=	gpsim>=20050905nb31
BUILDLINK_PKGSRCDIR.gpsim?=	../../emulators/gpsim-devel

.include "../../x11/gtk2/buildlink3.mk"
.endif # GPSIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpsim
