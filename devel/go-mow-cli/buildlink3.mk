# $NetBSD: buildlink3.mk,v 1.1 2016/07/16 13:03:42 bsiegert Exp $

BUILDLINK_TREE+=	go-mow-cli

.if !defined(GO_MOW_CLI_BUILDLINK3_MK)
GO_MOW_CLI_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-mow-cli=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-mow-cli?=		build

BUILDLINK_API_DEPENDS.go-mow-cli+=	go-mow-cli>=0.0.20160221
BUILDLINK_PKGSRCDIR.go-mow-cli?=	../../devel/go-mow-cli
.endif	# GO_MOW_CLI_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-mow-cli
