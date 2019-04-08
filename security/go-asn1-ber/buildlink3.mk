# $NetBSD: buildlink3.mk,v 1.1 2019/04/08 16:14:51 adam Exp $

BUILDLINK_TREE+=	go-asn1-ber

.if !defined(GO_ASN1_BER_BUILDLINK3_MK)
GO_ASN1_BER_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-asn1-ber=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-asn1-ber?=	build

BUILDLINK_API_DEPENDS.go-asn1-ber+=	go-asn1-ber>=1.3
BUILDLINK_PKGSRCDIR.go-asn1-ber?=	../../security/go-asn1-ber
.endif	# GO_ASN1_BER_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-asn1-ber
