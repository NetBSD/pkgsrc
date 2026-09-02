# $NetBSD: buildlink3.mk,v 1.45 2026/09/02 19:03:18 wiz Exp $

BUILDLINK_TREE+=	ksmtp

.if !defined(KSMTP_BUILDLINK3_MK)
KSMTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ksmtp+=	ksmtp>=25.08.3
BUILDLINK_ABI_DEPENDS.ksmtp?=	ksmtp>=25.08.3nb6
BUILDLINK_PKGSRCDIR.ksmtp?=	../../mail/ksmtp

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../mail/kmime/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KSMTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ksmtp
