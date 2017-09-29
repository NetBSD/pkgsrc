# $NetBSD: buildlink3.mk,v 1.1.1.1 2017/09/29 06:17:06 alnsn Exp $

BUILDLINK_TREE+=	go-goptlib

.if !defined(GO_GOPTLIB_BUILDLINK3_MK)
GO_GOPTLIB_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-goptlib=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-goptlib?=		build

BUILDLINK_API_DEPENDS.go-goptlib+=	go-goptlib>=0.7
BUILDLINK_PKGSRCDIR.go-goptlib?=	../../devel/go-goptlib
.endif	# GO_GOPTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-goptlib
