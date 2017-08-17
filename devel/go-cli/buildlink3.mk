# $NetBSD: buildlink3.mk,v 1.1 2017/08/17 01:19:56 gavan Exp $

BUILDLINK_TREE+=	go-cli

.if !defined(GO_CLI_BUILDLINK3_MK)
GO_CLI_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-cli=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-cli?=		build

BUILDLINK_API_DEPENDS.go-cli+=		go-cli>=1.20.0
BUILDLINK_PKGSRCDIR.go-cli?=		../../devel/go-cli

.endif  # GO_CLI_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-cli

