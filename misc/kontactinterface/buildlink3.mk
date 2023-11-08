# $NetBSD: buildlink3.mk,v 1.3 2023/11/08 13:20:09 wiz Exp $

BUILDLINK_TREE+=	kontactinterface

.if !defined(KONTACTINTERFACE_BUILDLINK3_MK)
KONTACTINTERFACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kontactinterface+=	kontactinterface>=20.04.1
BUILDLINK_ABI_DEPENDS.kontactinterface?=		kontactinterface>=23.04.3nb2
BUILDLINK_PKGSRCDIR.kontactinterface?=		../../misc/kontactinterface

.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KONTACTINTERFACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kontactinterface
