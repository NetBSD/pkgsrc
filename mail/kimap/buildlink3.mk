# $NetBSD: buildlink3.mk,v 1.46 2026/09/06 11:02:54 markd Exp $

BUILDLINK_TREE+=	kimap

.if !defined(KIMAP_BUILDLINK3_MK)
KIMAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kimap+=	kimap>=25.08.2
BUILDLINK_ABI_DEPENDS.kimap?=	kimap>=26.08.0
BUILDLINK_PKGSRCDIR.kimap?=	../../mail/kimap

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../mail/kf6-kmime/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KIMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-kimap
