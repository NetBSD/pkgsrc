# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:14 jperkin Exp $

BUILDLINK_TREE+=	go-crypt

.if !defined(GO_CRYPT_BUILDLINK3_MK)
GO_CRYPT_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-crypt=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-crypt?=		build

BUILDLINK_API_DEPENDS.go-crypt+=	go-crypt>=0.0.2
BUILDLINK_PKGSRCDIR.go-crypt?=		../../security/go-crypt

.endif  # GO_CRYPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-crypt
