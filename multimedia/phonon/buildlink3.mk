# $NetBSD: buildlink3.mk,v 1.38 2025/10/23 20:38:39 wiz Exp $

BUILDLINK_TREE+=	phonon

.if !defined(PHONON_BUILDLINK3_MK)
PHONON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.phonon+=	phonon>=4.5.0
BUILDLINK_ABI_DEPENDS.phonon+=	phonon>=4.10.3nb21
BUILDLINK_PKGSRCDIR.phonon?=	../../multimedia/phonon

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.endif # PHONON_BUILDLINK3_MK

BUILDLINK_TREE+=	-phonon
