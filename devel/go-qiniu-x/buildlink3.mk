# $NetBSD: buildlink3.mk,v 1.1 2023/04/22 15:49:13 nikita Exp $

BUILDLINK_TREE+=	go-qiniu-x

.if !defined(GO_QINIU_X_BUILDLINK3_MK)
GO_QINIU_X_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-qiniu-x=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-qiniu-x?=	build

BUILDLINK_API_DEPENDS.go-qiniu-x+=		go-qiniu-x>=1.11.9
BUILDLINK_PKGSRCDIR.go-qiniu-x?=		../../devel/go-qiniu-x

.endif  # GO_QINIU_X_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-qiniu-x
