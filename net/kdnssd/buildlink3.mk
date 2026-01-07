# $NetBSD: buildlink3.mk,v 1.44 2026/01/07 08:48:19 wiz Exp $

BUILDLINK_TREE+=	kdnssd

.if !defined(KDNSSD_BUILDLINK3_MK)
KDNSSD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdnssd+=	kdnssd>=5.19.0
BUILDLINK_ABI_DEPENDS.kdnssd?=	kdnssd>=5.116.0nb8
BUILDLINK_PKGSRCDIR.kdnssd?=	../../net/kdnssd

.include "../../net/avahi/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDNSSD_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdnssd
