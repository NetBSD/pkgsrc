# $NetBSD: buildlink3.mk,v 1.1 2018/07/18 02:38:08 minskim Exp $

BUILDLINK_TREE+=	go-sync

.if !defined(GO_SYNC_BUILDLINK3_MK)
GO_SYNC_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-sync=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-sync?=		build

BUILDLINK_API_DEPENDS.go-sync+=	go-sync>=0.0.20180314
BUILDLINK_PKGSRCDIR.go-sync?=	../../devel/go-sync

.include "../../net/go-net/buildlink3.mk"
.endif	# GO_SYNC_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-sync
