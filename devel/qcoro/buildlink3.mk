# $NetBSD: buildlink3.mk,v 1.5 2026/09/02 19:01:43 wiz Exp $

BUILDLINK_TREE+=	qcoro

.if !defined(QCORO_BUILDLINK3_MK)
QCORO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qcoro+=	qcoro>=0.12.0
BUILDLINK_ABI_DEPENDS.qcoro?=	qcoro>=0.12.0nb4
BUILDLINK_PKGSRCDIR.qcoro?=	../../devel/qcoro

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../net/qt6-qtwebsockets/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QCORO_BUILDLINK3_MK

BUILDLINK_TREE+=	-qcoro
