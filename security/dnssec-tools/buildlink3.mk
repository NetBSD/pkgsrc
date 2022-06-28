# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:35:35 wiz Exp $

BUILDLINK_TREE+=	dnssec-tools

.if !defined(DNSSEC_TOOLS_BUILDLINK3_MK)
DNSSEC_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dnssec-tools+=	dnssec-tools>=1.7
BUILDLINK_ABI_DEPENDS.dnssec-tools?=	dnssec-tools>=2.2.3nb2
BUILDLINK_PKGSRCDIR.dnssec-tools?=	../../security/dnssec-tools

.endif	# DNSSEC_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-dnssec-tools
