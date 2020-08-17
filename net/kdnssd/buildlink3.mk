# $NetBSD: buildlink3.mk,v 1.25 2020/08/17 20:17:39 leot Exp $

BUILDLINK_TREE+=	kdnssd

.if !defined(KDNSSD_BUILDLINK3_MK)
KDNSSD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdnssd+=	kdnssd>=5.19.0
BUILDLINK_ABI_DEPENDS.kdnssd?=	kdnssd>=5.70.0nb1
BUILDLINK_PKGSRCDIR.kdnssd?=	../../net/kdnssd

.include "../../net/avahi/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDNSSD_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdnssd
