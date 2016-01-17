# $NetBSD: buildlink3.mk,v 1.1 2016/01/17 15:03:14 jaapb Exp $

BUILDLINK_TREE+=	ktp-contact-list

.if !defined(KTP_CONTACT_LIST_BUILDLINK3_MK)
KTP_CONTACT_LIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ktp-contact-list+=	ktp-contact-list>=0.9.0
BUILDLINK_PKGSRCDIR.ktp-contact-list?=	../../chat/ktp-contact-list

.endif	# KTP_CONTACT_LIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-ktp-contact-list
