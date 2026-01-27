# $NetBSD: buildlink3.mk,v 1.17 2026/01/27 08:40:22 wiz Exp $

BUILDLINK_TREE+=	messagelib

.if !defined(MESSAGELIB_BUILDLINK3_MK)
MESSAGELIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.messagelib+=	messagelib>=25.08.3
BUILDLINK_ABI_DEPENDS.messagelib?=	messagelib>=25.08.3nb3
BUILDLINK_PKGSRCDIR.messagelib?=	../../net/messagelib

.include "../../mail/kmailtransport/buildlink3.mk"
.include "../../mail/kmbox/buildlink3.mk"
.include "../../misc/kidentitymanagement/buildlink3.mk"
.include "../../misc/libgravatar/buildlink3.mk"
.include "../../misc/pimcommon/buildlink3.mk"
.include "../../security/libkleo/buildlink3.mk"
.include "../../www/qt6-qtwebengine/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# MESSAGELIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-messagelib
