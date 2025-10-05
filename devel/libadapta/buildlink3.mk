# $NetBSD: buildlink3.mk,v 1.3 2025/10/05 19:25:50 js Exp $

BUILDLINK_TREE+=	libadapta

.if !defined(LIBADAPTA_BUILDLINK3_MK)
LIBADAPTA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libadapta+=	libadapta>=1.5.0
BUILDLINK_ABI_DEPENDS.libadapta?=		libadapta>=1.5.0nb3
BUILDLINK_PKGSRCDIR.libadapta?=		../../devel/libadapta

.include "../../devel/appstream/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.endif	# LIBADAPTA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libadapta
