# $NetBSD: buildlink3.mk,v 1.13 2026/11/11 11:55:42 wiz Exp $

BUILDLINK_TREE+=	libayatana-indicator

.if !defined(LIBAYATANA_INDICATOR_BUILDLINK3_MK)
LIBAYATANA_INDICATOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libayatana-indicator+=	libayatana-indicator>=0.9.4
BUILDLINK_ABI_DEPENDS.libayatana-indicator?=	libayatana-indicator>=0.9.4nb12
BUILDLINK_PKGSRCDIR.libayatana-indicator?=	../../sysutils/libayatana-indicator

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/ayatana-ido/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# LIBAYATANA_INDICATOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libayatana-indicator
