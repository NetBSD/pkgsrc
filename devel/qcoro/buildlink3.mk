# $NetBSD: buildlink3.mk,v 1.6 2026/09/27 11:35:48 tnn Exp $

BUILDLINK_TREE+=	qcoro

.if !defined(QCORO_BUILDLINK3_MK)
QCORO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qcoro+=	qcoro>=0.12.0
BUILDLINK_ABI_DEPENDS.qcoro?=	qcoro>=0.12.0nb5
BUILDLINK_PKGSRCDIR.qcoro?=	../../devel/qcoro

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../net/qt6-qtwebsockets/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QCORO_BUILDLINK3_MK

BUILDLINK_TREE+=	-qcoro
