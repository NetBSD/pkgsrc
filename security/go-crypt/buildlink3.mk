# $NetBSD: buildlink3.mk,v 1.1 2017/08/17 01:59:34 gavan Exp $

BUILDLINK_TREE+=	go-crypt

.if !defined(GO_CRYPT_BUILDLINK3_MK)
GO_CRYPT_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-crypt=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-crypt?=		build

BUILDLINK_API_DEPENDS.go-crypt+=	go-crypt>=0.0.2
BUILDLINK_PKGSRCDIR.go-crypt?=		../../security/go-crypt

.endif  # GO_CRYPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-crypt

