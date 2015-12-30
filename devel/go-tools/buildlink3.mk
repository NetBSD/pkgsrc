# $NetBSD: buildlink3.mk,v 1.1 2015/12/30 14:07:58 bsiegert Exp $

BUILDLINK_TREE+=	go-tools

.if !defined(GO_TOOLS_BUILDLINK3_MK)
GO_TOOLS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-tools=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-tools?=		build

BUILDLINK_API_DEPENDS.go-tools+=	go-tools>=1.5
BUILDLINK_PKGSRCDIR.go-tools?=	../../devel/go-tools

.include "../../devel/google-api-go-client/buildlink3.mk"
.endif	# GO_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-tools
