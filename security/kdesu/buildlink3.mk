# $NetBSD: buildlink3.mk,v 1.12 2018/12/09 18:52:07 adam Exp $

BUILDLINK_TREE+=	kdesu

.if !defined(KDESU_BUILDLINK3_MK)
KDESU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdesu+=	kdesu>=5.21.0
BUILDLINK_ABI_DEPENDS.kdesu?=	kdesu>=5.47.0nb3
BUILDLINK_PKGSRCDIR.kdesu?=	../../security/kdesu

.include "../../devel/kpty/buildlink3.mk"
.include "../../devel/kservice/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDESU_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdesu
