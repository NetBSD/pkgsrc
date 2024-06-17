# $NetBSD: buildlink3.mk,v 1.1 2024/06/17 11:25:15 skrll Exp $

BUILDLINK_DEPMETHOD.opensbi-visionfive2?=	build

BUILDLINK_TREE+=	opensbi-visionfive2

.if !defined(OPENSBI_VISIONFIVE2_BUILDLINK3_MK)
OPENSBI_VISIONFIVE2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opensbi-visionfive2+=	opensbi-visionfive2>=1.4
BUILDLINK_PKGSRCDIR.opensbi-visionfive2?=	../../sysutils/opensbi-visionfive2
.endif	# OPENSBI_VISIONFIVE2_BUILDLINK3_MK

BUILDLINK_TREE+=	-opensbi-visionfive2

