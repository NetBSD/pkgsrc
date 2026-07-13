# $NetBSD: buildlink3.mk,v 1.59 2026/07/13 04:35:33 wiz Exp $

BUILDLINK_TREE+=	krunner

.if !defined(KRUNNER_BUILDLINK3_MK)
KRUNNER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.krunner+=	krunner>=5.21.0
BUILDLINK_ABI_DEPENDS.krunner?=	krunner>=5.116.0nb10
BUILDLINK_PKGSRCDIR.krunner?=	../../devel/krunner

.include "../../x11/plasma-framework/buildlink3.mk"
.include "../../devel/threadweaver/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KRUNNER_BUILDLINK3_MK

BUILDLINK_TREE+=	-krunner
