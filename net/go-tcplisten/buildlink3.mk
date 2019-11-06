# $NetBSD: buildlink3.mk,v 1.1 2019/11/06 11:54:49 ng0 Exp $

BUILDLINK_TREE+=	go-tcplisten

.if !defined(GO_TCPLISTEN_BUILDLINK3_MK)
GO_TCPLISTEN_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-tcplisten=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-tcplisten?=	build

BUILDLINK_API_DEPENDS.go-tcplisten+=	go-tcplisten>=0.0.0
BUILDLINK_PKGSRCDIR.go-tcplisten?=	../../net/go-tcplisten
.endif	# GO_TCPLISTEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-tcplisten
