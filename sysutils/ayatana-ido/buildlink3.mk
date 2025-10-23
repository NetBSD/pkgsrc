# $NetBSD: buildlink3.mk,v 1.7 2025/10/23 20:39:14 wiz Exp $

BUILDLINK_TREE+=	ayatana-ido

.if !defined(AYATANA_IDO_BUILDLINK3_MK)
AYATANA_IDO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ayatana-ido+=	ayatana-ido>=0.10.2
BUILDLINK_ABI_DEPENDS.ayatana-ido?=	ayatana-ido>=0.10.2nb7
BUILDLINK_PKGSRCDIR.ayatana-ido?=	../../sysutils/ayatana-ido

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# AYATANA_IDO_BUILDLINK3_MK

BUILDLINK_TREE+=	-ayatana-ido
