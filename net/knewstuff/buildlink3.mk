# $NetBSD: buildlink3.mk,v 1.34 2021/07/30 12:27:04 ryoon Exp $

BUILDLINK_TREE+=	knewstuff

.if !defined(KNEWSTUFF_BUILDLINK3_MK)
KNEWSTUFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.knewstuff+=	knewstuff>=5.21.0
BUILDLINK_ABI_DEPENDS.knewstuff?=	knewstuff>=5.80.0nb2
BUILDLINK_PKGSRCDIR.knewstuff?=		../../net/knewstuff

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KNEWSTUFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-knewstuff
