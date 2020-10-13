# $NetBSD: buildlink3.mk,v 1.1 2020/10/13 02:33:10 maya Exp $

BUILDLINK_TREE+=	go-walker

.if !defined(GO_walker_BUILDLINK3_MK)
GO_walker_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-walker=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-walker?=		build

BUILDLINK_API_DEPENDS.go-walker+=	go-walker>=0.0
BUILDLINK_PKGSRCDIR.go-walker?=		../../devel/go-walker

.include "../../devel/go-sync/buildlink3.mk"
.endif  # GO_walker_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-walker
