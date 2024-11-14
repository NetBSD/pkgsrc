# $NetBSD: buildlink3.mk,v 1.35 2024/11/14 22:18:37 wiz Exp $

BUILDLINK_TREE+=	karchive

.if !defined(KARCHIVE_BUILDLINK3_MK)
KARCHIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.karchive+=	karchive>=5.18.0
BUILDLINK_ABI_DEPENDS.karchive?=	karchive>=5.116.0nb3
BUILDLINK_PKGSRCDIR.karchive?=		../../archivers/karchive

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KARCHIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-karchive
