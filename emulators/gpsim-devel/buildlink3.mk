# $NetBSD: buildlink3.mk,v 1.30 2014/05/05 00:47:49 ryoon Exp $

BUILDLINK_TREE+=	gpsim

.if !defined(GPSIM_BUILDLINK3_MK)
GPSIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gpsim+=	gpsim>=20050905
BUILDLINK_ABI_DEPENDS.gpsim+=	gpsim>=20050905nb26
BUILDLINK_PKGSRCDIR.gpsim?=	../../emulators/gpsim-devel

.include "../../x11/gtk2/buildlink3.mk"
.endif # GPSIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gpsim
