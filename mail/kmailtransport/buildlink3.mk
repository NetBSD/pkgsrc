# $NetBSD: buildlink3.mk,v 1.18 2026/02/06 10:05:12 wiz Exp $

BUILDLINK_TREE+=	kmailtransport

.if !defined(KMAILTRANSPORT_BUILDLINK3_MK)
KMAILTRANSPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kmailtransport+=	kmailtransport>=25.08.2
BUILDLINK_ABI_DEPENDS.kmailtransport?=	kmailtransport>=25.08.3nb3
BUILDLINK_PKGSRCDIR.kmailtransport?=	../../mail/kmailtransport

.include "../../devel/libkgapi/buildlink3.mk"
.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../mail/akonadi-mime/buildlink3.mk"
.include "../../mail/ksmtp/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/qt6-qtkeychain/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KMAILTRANSPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-kmailtransport
