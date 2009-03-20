# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:24 joerg Exp $

BUILDLINK_TREE+=	ipa

.if !defined(IPA_BUILDLINK3_MK)
IPA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ipa+=	ipa>=2.0
BUILDLINK_PKGSRCDIR.ipa?=	../../sysutils/ipa
BUILDLINK_DEPMETHOD.ipa?=	build
.endif # IPA_BUILDLINK3_MK

BUILDLINK_TREE+=	-ipa
