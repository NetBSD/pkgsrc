# $NetBSD: buildlink3.mk,v 1.3 2020/02/03 14:51:55 bsiegert Exp $

BUILDLINK_TREE+=	go-crypto-acme

.if !defined(GO_CRYPTO_ACME_BUILDLINK3_MK)
GO_CRYPTO_ACME_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-crypto-acme=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-crypto-acme?=		build

BUILDLINK_API_DEPENDS.go-crypto-acme+=	go-crypto-acme>=0.0.20170317
BUILDLINK_PKGSRCDIR.go-crypto-acme?=	../../security/go-crypto-acme

.include "../../net/go-net/buildlink3.mk"
.endif	# GO_CRYPTO_ACME_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-crypto-acme
