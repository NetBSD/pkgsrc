# $NetBSD: buildlink3.mk,v 1.1 2018/11/18 07:59:34 ryoon Exp $

BUILDLINK_TREE+=	go-try

.if !defined(GO_TRY_BUILDLINK3_MK)
GO_TRY_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-try=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-try?=		build

BUILDLINK_API_DEPENDS.go-try+=	go-try>=1.0.0.0
BUILDLINK_PKGSRCDIR.go-try?=	../../devel/go-try
.endif	# GO_TRY_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-try
