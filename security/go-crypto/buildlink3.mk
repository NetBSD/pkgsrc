# $NetBSD: buildlink3.mk,v 1.6 2020/02/03 13:14:20 bsiegert Exp $

BUILDLINK_TREE+=	go-crypto

.if !defined(GO_CRYPTO_BUILDLINK3_MK)
GO_CRYPTO_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-crypto=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-crypto?=		build

BUILDLINK_API_DEPENDS.go-crypto+=	go-crypto>=0.0.20200122
BUILDLINK_PKGSRCDIR.go-crypto?=		../../security/go-crypto

.include "../../devel/go-sys/buildlink3.mk"
.endif	# GO_CRYPTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-crypto
