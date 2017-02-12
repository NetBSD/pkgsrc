# $NetBSD: buildlink3.mk,v 1.4 2017/02/12 06:24:36 ryoon Exp $

BUILDLINK_TREE+=	karchive

.if !defined(KARCHIVE_BUILDLINK3_MK)
KARCHIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.karchive+=	karchive>=5.18.0
BUILDLINK_ABI_DEPENDS.karchive?=	karchive>=5.25.0nb3
BUILDLINK_PKGSRCDIR.karchive?=	../../archivers/karchive

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KARCHIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-karchive
