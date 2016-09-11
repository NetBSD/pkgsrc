# $NetBSD: buildlink3.mk,v 1.1 2016/09/11 08:15:43 bsiegert Exp $

BUILDLINK_TREE+=	go-glog

.if !defined(GO_GLOG_BUILDLINK3_MK)
GO_GLOG_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-glog=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-glog?=		build

BUILDLINK_API_DEPENDS.go-glog+=	go-glog>=20160125
BUILDLINK_PKGSRCDIR.go-glog?=	../../devel/go-glog
.endif	# GO_GLOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-glog
