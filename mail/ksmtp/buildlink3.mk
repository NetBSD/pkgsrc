# $NetBSD: buildlink3.mk,v 1.26 2023/10/24 22:09:45 wiz Exp $

BUILDLINK_TREE+=	ksmtp

.if !defined(KSMTP_BUILDLINK3_MK)
KSMTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ksmtp+=	ksmtp>=17.12.1
BUILDLINK_ABI_DEPENDS.ksmtp?=	ksmtp>=23.04.3nb1
BUILDLINK_PKGSRCDIR.ksmtp?=	../../mail/ksmtp

.include "../../devel/kio/buildlink3.mk"
.include "../../mail/kmime/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KSMTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ksmtp
