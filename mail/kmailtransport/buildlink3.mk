# $NetBSD: buildlink3.mk,v 1.1 2023/08/16 04:06:49 markd Exp $

BUILDLINK_TREE+=	kmailtransport

.if !defined(KMAILTRANSPORT_BUILDLINK3_MK)
KMAILTRANSPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kmailtransport+=	kmailtransport>=17.12.1
BUILDLINK_PKGSRCDIR.kmailtransport?=	../../mail/kmailtransport

.include "../../devel/kcmutils/buildlink3.mk"
.include "../../mail/akonadi-mime/buildlink3.mk"
.include "../../mail/ksmtp/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KMAILTRANSPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-kmailtransport
