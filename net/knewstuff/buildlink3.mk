# $NetBSD: buildlink3.mk,v 1.38 2022/07/02 16:53:32 ryoon Exp $

BUILDLINK_TREE+=	knewstuff

.if !defined(KNEWSTUFF_BUILDLINK3_MK)
KNEWSTUFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.knewstuff+=	knewstuff>=5.21.0
BUILDLINK_ABI_DEPENDS.knewstuff?=	knewstuff>=5.93.0nb1
BUILDLINK_PKGSRCDIR.knewstuff?=		../../net/knewstuff

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KNEWSTUFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-knewstuff
