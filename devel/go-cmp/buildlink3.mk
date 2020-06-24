# $NetBSD: buildlink3.mk,v 1.2 2020/06/24 22:31:49 nikita Exp $

BUILDLINK_TREE+=	go-cmp

.if !defined(GO_CMP_BUILDLINK3_MK)
GO_CMP_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-cmp=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-cmp?=		build

BUILDLINK_API_DEPENDS.go-cmp+=		go-cmp>=0.4.0
BUILDLINK_PKGSRCDIR.go-cmp?=		../../devel/go-cmp

.include "../../devel/go-xerrors/buildlink3.mk"
.endif	# GO_CMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-cmp
