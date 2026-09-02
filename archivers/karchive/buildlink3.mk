# $NetBSD: buildlink3.mk,v 1.40 2026/09/02 19:00:42 wiz Exp $

BUILDLINK_TREE+=	karchive

.if !defined(KARCHIVE_BUILDLINK3_MK)
KARCHIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.karchive+=	karchive>=5.18.0
BUILDLINK_ABI_DEPENDS.karchive?=	karchive>=5.116.0nb10
BUILDLINK_PKGSRCDIR.karchive?=		../../archivers/karchive

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KARCHIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-karchive
