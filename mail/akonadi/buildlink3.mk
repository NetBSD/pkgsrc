# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:54 joerg Exp $

BUILDLINK_TREE+=	akonadi

.if !defined(AKONADI_BUILDLINK3_MK)
AKONADI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.akonadi+=	akonadi>=0.82.0
BUILDLINK_PKGSRCDIR.akonadi?=	../../mail/akonadi

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.endif # AKONADI_BUILDLINK3_MK

BUILDLINK_TREE+=	-akonadi
