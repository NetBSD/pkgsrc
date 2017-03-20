# $NetBSD: buildlink3.mk,v 1.3 2017/03/20 22:53:45 bsiegert Exp $

BUILDLINK_TREE+=	go-crypto

.if !defined(GO_CRYPTO_BUILDLINK3_MK)
GO_CRYPTO_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-crypto=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-crypto?=		build

BUILDLINK_API_DEPENDS.go-crypto+=	go-crypto>=0.0.20170317
BUILDLINK_PKGSRCDIR.go-crypto?=	../../security/go-crypto

.endif	# GO_CRYPTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-crypto
