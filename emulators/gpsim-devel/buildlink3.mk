# $NetBSD: buildlink3.mk,v 1.37 2018/11/12 03:51:15 ryoon Exp $

BUILDLINK_TREE+=	gpsim

.if !defined(GPSIM_BUILDLINK3_MK)
GPSIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpsim+=	gpsim>=20050905
BUILDLINK_ABI_DEPENDS.gpsim+=	gpsim>=20050905nb33
BUILDLINK_PKGSRCDIR.gpsim?=	../../emulators/gpsim-devel

.include "../../x11/gtk2/buildlink3.mk"
.endif # GPSIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpsim
