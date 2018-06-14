# $NetBSD: buildlink3.mk,v 1.1 2018/06/14 15:15:58 minskim Exp $

BUILDLINK_TREE+=	go-debounce

.if !defined(GO_DEBOUNCE_BUILDLINK3_MK)
GO_DEBOUNCE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-debounce=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-debounce?=	build

BUILDLINK_API_DEPENDS.go-debounce+=	go-debounce>=1.1.0
BUILDLINK_PKGSRCDIR.go-debounce?=	../../devel/go-debounce
.endif	# GO_DEBOUNCE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-debounce
