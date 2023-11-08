# $NetBSD: buildlink3.mk,v 1.3 2023/11/08 13:19:56 wiz Exp $

BUILDLINK_TREE+=	kmailtransport

.if !defined(KMAILTRANSPORT_BUILDLINK3_MK)
KMAILTRANSPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kmailtransport+=	kmailtransport>=17.12.1
BUILDLINK_ABI_DEPENDS.kmailtransport?=	kmailtransport>=23.04.3nb2
BUILDLINK_PKGSRCDIR.kmailtransport?=	../../mail/kmailtransport

.include "../../devel/kcmutils/buildlink3.mk"
.include "../../mail/akonadi-mime/buildlink3.mk"
.include "../../mail/ksmtp/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KMAILTRANSPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-kmailtransport
