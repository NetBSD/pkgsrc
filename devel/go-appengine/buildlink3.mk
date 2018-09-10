# $NetBSD: buildlink3.mk,v 1.1 2018/09/10 22:43:58 minskim Exp $

BUILDLINK_TREE+=	go-appengine

.if !defined(GO_APPENGINE_BUILDLINK3_MK)
GO_APPENGINE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-appengine=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-appengine?=	build

BUILDLINK_API_DEPENDS.go-appengine+=	go-appengine>=1.1.0
BUILDLINK_PKGSRCDIR.go-appengine?=	../../devel/go-appengine

.include "../../devel/go-protobuf/buildlink3.mk"
.include "../../net/go-net/buildlink3.mk"
.include "../../textproc/go-text/buildlink3.mk"
.endif	# GO_APPENGINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-appengine
