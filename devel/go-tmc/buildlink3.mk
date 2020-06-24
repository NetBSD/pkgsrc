# $NetBSD: buildlink3.mk,v 1.1 2020/06/24 20:35:00 nikita Exp $

BUILDLINK_TREE+=	go-tmc

.if !defined(GO_TMC_BUILDLINK3_MK)
GO_TMC_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-tmc=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-tmc?=		build

BUILDLINK_API_DEPENDS.go-tmc+=		go-tmc>=0.5.1
BUILDLINK_PKGSRCDIR.go-tmc?=		../../devel/go-tmc
.endif	# GO_TMC_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-tmc
