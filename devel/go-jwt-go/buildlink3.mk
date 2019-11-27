# $NetBSD: buildlink3.mk,v 1.1 2019/11/27 10:27:09 ng0 Exp $

BUILDLINK_TREE+=	go-jwt-go

.if !defined(GO_JWT_GO_BUILDLINK3_MK)
GO_JWT_GO_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-jwt-go=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-jwt-go?=		build

BUILDLINK_API_DEPENDS.go-jwt-go+=	go-jwt-go>=3.2.0
BUILDLINK_PKGSRCDIR.go-jwt-go?=		../../devel/go-jwt-go
.endif	# GO_JWT_GO_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-jwt-go
