# $NetBSD: buildlink3.mk,v 1.23 2026/09/27 11:37:40 tnn Exp $

BUILDLINK_TREE+=	kontactinterface

.if !defined(KONTACTINTERFACE_BUILDLINK3_MK)
KONTACTINTERFACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kontactinterface+=	kontactinterface>=25.08.2
BUILDLINK_ABI_DEPENDS.kontactinterface?=	kontactinterface>=26.08.0nb1
BUILDLINK_PKGSRCDIR.kontactinterface?=		../../misc/kontactinterface

.include "../../devel/kf6-kparts/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KONTACTINTERFACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kontactinterface
