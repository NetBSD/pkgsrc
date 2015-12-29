# $NetBSD: buildlink3.mk,v 1.1 2015/12/29 21:49:21 bsiegert Exp $

BUILDLINK_TREE+=	go-flags-svent

.if !defined(GO_FLAGS_SVENT_BUILDLINK3_MK)
GO_FLAGS_SVENT_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-flags-svent=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-flags-svent?=		build

BUILDLINK_API_DEPENDS.go-flags-svent+=	go-flags-svent>=0.0.20141123
BUILDLINK_PKGSRCDIR.go-flags-svent?=	../../devel/go-flags-svent
.endif	# GO_FLAGS_SVENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-flags-svent
