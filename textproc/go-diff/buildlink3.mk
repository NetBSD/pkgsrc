# $NetBSD: buildlink3.mk,v 1.1 2018/11/18 08:24:23 ryoon Exp $

BUILDLINK_TREE+=	go-go-diff

.if !defined(GO_GO_DIFF_BUILDLINK3_MK)
GO_GO_DIFF_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-go-diff=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-go-diff?=	build

BUILDLINK_API_DEPENDS.go-go-diff+=	go-go-diff>=1.0.0
BUILDLINK_PKGSRCDIR.go-go-diff?=	../../textproc/go-diff
.endif	# GO_GO_DIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-go-diff
