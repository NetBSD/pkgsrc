# $NetBSD: buildlink3.mk,v 1.8 2026/02/06 10:04:33 wiz Exp $

BUILDLINK_TREE+=	libadapta

.if !defined(LIBADAPTA_BUILDLINK3_MK)
LIBADAPTA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libadapta+=	libadapta>=1.5.0
BUILDLINK_ABI_DEPENDS.libadapta?=		libadapta>=1.5.0nb8
BUILDLINK_PKGSRCDIR.libadapta?=		../../devel/libadapta

.include "../../devel/appstream/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.endif	# LIBADAPTA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libadapta
