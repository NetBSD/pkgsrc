# $NetBSD: buildlink3.mk,v 1.1 2018/07/17 03:54:51 minskim Exp $

BUILDLINK_TREE+=	go-tablewriter

.if !defined(GO_TABLEWRITER_BUILDLINK3_MK)
GO_TABLEWRITER_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-tablewriter=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-tablewriter?=		build

BUILDLINK_API_DEPENDS.go-tablewriter+=	go-tablewriter>=0.0.20180506
BUILDLINK_PKGSRCDIR.go-tablewriter?=	../../textproc/go-tablewriter

.include "../../textproc/go-runewidth/buildlink3.mk"
.endif	# GO_TABLEWRITER_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-tablewriter
