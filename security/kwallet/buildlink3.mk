# $NetBSD: buildlink3.mk,v 1.35 2022/09/11 12:51:10 wiz Exp $

BUILDLINK_TREE+=	kwallet

.if !defined(KWALLET_BUILDLINK3_MK)
KWALLET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kwallet+=	kwallet>=5.19.0
BUILDLINK_ABI_DEPENDS.kwallet?=	kwallet>=5.93.0nb3
BUILDLINK_PKGSRCDIR.kwallet?=	../../security/kwallet

.include "../../devel/knotifications/buildlink3.mk"
.include "../../devel/kservice/buildlink3.mk"
.include "../../graphics/kiconthemes/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KWALLET_BUILDLINK3_MK

BUILDLINK_TREE+=	-kwallet
