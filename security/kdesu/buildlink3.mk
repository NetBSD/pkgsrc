# $NetBSD: buildlink3.mk,v 1.19 2020/08/17 20:17:41 leot Exp $

BUILDLINK_TREE+=	kdesu

.if !defined(KDESU_BUILDLINK3_MK)
KDESU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdesu+=	kdesu>=5.21.0
BUILDLINK_ABI_DEPENDS.kdesu?=	kdesu>=5.70.0nb1
BUILDLINK_PKGSRCDIR.kdesu?=	../../security/kdesu

.include "../../devel/kpty/buildlink3.mk"
.include "../../devel/kservice/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDESU_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdesu
