# $NetBSD: buildlink3.mk,v 1.2 2024/10/20 14:04:31 wiz Exp $

BUILDLINK_TREE+=	ayatana-ido

.if !defined(AYATANA_IDO_BUILDLINK3_MK)
AYATANA_IDO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ayatana-ido+=	ayatana-ido>=0.10.2
BUILDLINK_ABI_DEPENDS.ayatana-ido?=	ayatana-ido>=0.10.2nb1
BUILDLINK_PKGSRCDIR.ayatana-ido?=	../../sysutils/ayatana-ido

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# AYATANA_IDO_BUILDLINK3_MK

BUILDLINK_TREE+=	-ayatana-ido
