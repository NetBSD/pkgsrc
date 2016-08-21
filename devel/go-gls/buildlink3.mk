# $NetBSD: buildlink3.mk,v 1.1 2016/08/21 09:14:25 bsiegert Exp $

BUILDLINK_TREE+=	go-gls

.if !defined(GO_GLS_BUILDLINK3_MK)
GO_GLS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-gls=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-gls?=		build

BUILDLINK_API_DEPENDS.go-gls+=	go-gls>=4.2.0
BUILDLINK_PKGSRCDIR.go-gls?=	../../devel/go-gls
.endif	# GO_GLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-gls
