# $NetBSD: buildlink3.mk,v 1.14 2018/03/12 11:15:28 wiz Exp $

BUILDLINK_TREE+=	krunner

.if !defined(KRUNNER_BUILDLINK3_MK)
KRUNNER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.krunner+=	krunner>=5.21.0
BUILDLINK_ABI_DEPENDS.krunner?=	krunner>=5.41.0nb3
BUILDLINK_PKGSRCDIR.krunner?=	../../devel/krunner

.include "../../x11/plasma-framework/buildlink3.mk"
.include "../../devel/threadweaver/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KRUNNER_BUILDLINK3_MK

BUILDLINK_TREE+=	-krunner
