# $NetBSD: buildlink3.mk,v 1.1 2018/11/18 07:49:26 ryoon Exp $

BUILDLINK_TREE+=	go-colour

.if !defined(GO_COLOUR_BUILDLINK3_MK)
GO_COLOUR_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-colour=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-colour?=		build

BUILDLINK_API_DEPENDS.go-colour+=	go-colour>=0.0.0.20160524
BUILDLINK_PKGSRCDIR.go-colour?=		../../devel/go-colour

.endif	# GO_COLOUR_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-colour
