# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:12 jperkin Exp $

BUILDLINK_TREE+=	go-cli

.if !defined(GO_CLI_BUILDLINK3_MK)
GO_CLI_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-cli=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-cli?=		build

BUILDLINK_API_DEPENDS.go-cli+=		go-cli>=1.20.0
BUILDLINK_PKGSRCDIR.go-cli?=		../../devel/go-cli

.endif  # GO_CLI_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-cli
