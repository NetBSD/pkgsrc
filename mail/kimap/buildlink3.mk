# $NetBSD: buildlink3.mk,v 1.29 2024/01/30 14:22:13 ryoon Exp $

BUILDLINK_TREE+=	kimap

.if !defined(KIMAP_BUILDLINK3_MK)
KIMAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kimap+=	kimap>=17.12.1
BUILDLINK_ABI_DEPENDS.kimap?=	kimap>=23.04.3nb4
BUILDLINK_PKGSRCDIR.kimap?=	../../mail/kimap

.include "../../devel/kio/buildlink3.mk"
.include "../../mail/kmime/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KIMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-kimap
