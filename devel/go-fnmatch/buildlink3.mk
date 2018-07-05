# $NetBSD: buildlink3.mk,v 1.1 2018/07/05 04:34:02 minskim Exp $

BUILDLINK_TREE+=	go-fnmatch

.if !defined(GO_FNMATCH_BUILDLINK3_MK)
GO_FNMATCH_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-fnmatch=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-fnmatch?=	build

BUILDLINK_API_DEPENDS.go-fnmatch+=	go-fnmatch>=0.0.20160404
BUILDLINK_PKGSRCDIR.go-fnmatch?=	../../devel/go-fnmatch
.endif	# GO_FNMATCH_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-fnmatch
