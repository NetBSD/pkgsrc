# $NetBSD: buildlink3.mk,v 1.10 2024/11/14 22:21:12 wiz Exp $

BUILDLINK_TREE+=	messagelib

.if !defined(MESSAGELIB_BUILDLINK3_MK)
MESSAGELIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.messagelib+=	messagelib>=20.04.1
BUILDLINK_ABI_DEPENDS.messagelib?=	messagelib>=23.08.4nb6
BUILDLINK_PKGSRCDIR.messagelib?=	../../net/messagelib

.include "../../mail/kmailtransport/buildlink3.mk"
.include "../../mail/kmbox/buildlink3.mk"
.include "../../misc/kidentitymanagement/buildlink3.mk"
.include "../../misc/libgravatar/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# MESSAGELIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-messagelib
