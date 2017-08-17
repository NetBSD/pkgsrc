# $NetBSD: buildlink3.mk,v 1.1 2017/08/17 02:02:27 gavan Exp $

BUILDLINK_TREE+=	go-etcd

.if !defined(GO_ETCD_BUILDLINK3_MK)
GO_ETCD_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-etcd=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-etcd?=		build

BUILDLINK_API_DEPENDS.go-etcd+=		go-etcd>=0.0
BUILDLINK_PKGSRCDIR.go-etcd?=		../../databases/go-etcd

.endif  # GO_ETCD_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-etcd

