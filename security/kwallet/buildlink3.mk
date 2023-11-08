# $NetBSD: buildlink3.mk,v 1.43 2023/11/08 13:20:47 wiz Exp $

BUILDLINK_TREE+=	kwallet

.if !defined(KWALLET_BUILDLINK3_MK)
KWALLET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kwallet+=	kwallet>=5.19.0
BUILDLINK_ABI_DEPENDS.kwallet?=	kwallet>=5.108.0nb3
BUILDLINK_PKGSRCDIR.kwallet?=	../../security/kwallet

.include "../../devel/knotifications/buildlink3.mk"
.include "../../devel/kservice/buildlink3.mk"
.include "../../graphics/kiconthemes/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KWALLET_BUILDLINK3_MK

BUILDLINK_TREE+=	-kwallet
