# $NetBSD: buildlink3.mk,v 1.21 2013/02/06 23:21:17 jperkin Exp $

BUILDLINK_TREE+=	akonadi

.if !defined(AKONADI_BUILDLINK3_MK)
AKONADI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.akonadi+=	akonadi>=0.82.0
BUILDLINK_ABI_DEPENDS.akonadi+=	akonadi>=1.7.2nb1
BUILDLINK_PKGSRCDIR.akonadi?=	../../mail/akonadi

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.endif # AKONADI_BUILDLINK3_MK

BUILDLINK_TREE+=	-akonadi
