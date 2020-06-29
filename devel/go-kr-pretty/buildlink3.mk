# $NetBSD: buildlink3.mk,v 1.1 2020/06/29 13:22:14 nikita Exp $

BUILDLINK_TREE+=	go-kr-pretty

.if !defined(GO_KR_PRETTY_BUILDLINK3_MK)
GO_KR_PRETTY_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-kr-pretty=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-kr-pretty?=	build

BUILDLINK_API_DEPENDS.go-kr-pretty+=	go-kr-pretty>=0.2.0
BUILDLINK_PKGSRCDIR.go-kr-pretty?=	../../devel/go-kr-pretty

.include "../../textproc/go-kr-text/buildlink3.mk"
.endif	# GO_KR_PRETTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-kr-pretty
