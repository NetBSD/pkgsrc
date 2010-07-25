# $NetBSD: buildlink3.mk,v 1.1 2010/07/25 19:23:06 pettai Exp $

BUILDLINK_TREE+=	dnssec-tools

.if !defined(DNSSEC_TOOLS_BUILDLINK3_MK)
DNSSEC_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dnssec-tools+=	dnssec-tools>=1.7
BUILDLINK_PKGSRCDIR.dnssec-tools?=	../../security/dnssec-tools

.endif	# DNSSEC_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-dnssec-tools
