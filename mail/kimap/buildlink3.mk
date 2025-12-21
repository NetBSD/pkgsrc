# $NetBSD: buildlink3.mk,v 1.39 2025/12/21 13:02:46 markd Exp $

BUILDLINK_TREE+=	kimap

.if !defined(KIMAP_BUILDLINK3_MK)
KIMAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kimap+=	kimap>=25.08.2
BUILDLINK_ABI_DEPENDS.kimap?=	kimap>=25.08.2
BUILDLINK_PKGSRCDIR.kimap?=	../../mail/kimap

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../mail/kmime/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KIMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-kimap
