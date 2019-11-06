# $NetBSD: buildlink3.mk,v 1.1 2019/11/06 13:40:23 ng0 Exp $

BUILDLINK_TREE+=	go-spew

.if !defined(GO_SPEW_BUILDLINK3_MK)
GO_SPEW_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-spew=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-spew?=		build

BUILDLINK_API_DEPENDS.go-spew+=		go-spew>=1.1.1
BUILDLINK_PKGSRCDIR.go-spew?=		../../devel/go-spew
.endif	# GO_SPEW_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-spew
