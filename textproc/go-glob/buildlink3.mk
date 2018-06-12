# $NetBSD: buildlink3.mk,v 1.1 2018/06/12 23:50:02 minskim Exp $

BUILDLINK_TREE+=	go-glob

.if !defined(GO_GLOB_BUILDLINK3_MK)
GO_GLOB_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-glob=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-glob?=		build

BUILDLINK_API_DEPENDS.go-glob+=	go-glob>=0.2.3
BUILDLINK_PKGSRCDIR.go-glob?=	../../textproc/go-glob
.endif	# GO_GLOB_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-glob
