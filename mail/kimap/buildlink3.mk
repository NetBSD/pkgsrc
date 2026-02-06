# $NetBSD: buildlink3.mk,v 1.42 2026/02/06 10:05:11 wiz Exp $

BUILDLINK_TREE+=	kimap

.if !defined(KIMAP_BUILDLINK3_MK)
KIMAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kimap+=	kimap>=25.08.2
BUILDLINK_ABI_DEPENDS.kimap?=	kimap>=25.08.3nb3
BUILDLINK_PKGSRCDIR.kimap?=	../../mail/kimap

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../mail/kmime/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KIMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-kimap
