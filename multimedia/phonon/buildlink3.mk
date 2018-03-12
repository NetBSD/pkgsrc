# $NetBSD: buildlink3.mk,v 1.29 2018/03/12 11:15:41 wiz Exp $

BUILDLINK_TREE+=	phonon

.if !defined(PHONON_BUILDLINK3_MK)
PHONON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.phonon+=	phonon>=4.5.0
BUILDLINK_ABI_DEPENDS.phonon+=	phonon>=4.9.1nb2
BUILDLINK_PKGSRCDIR.phonon?=	../../multimedia/phonon

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.endif # PHONON_BUILDLINK3_MK

BUILDLINK_TREE+=	-phonon
