# $NetBSD: buildlink3.mk,v 1.1 2020/06/29 13:04:01 nikita Exp $

BUILDLINK_TREE+=	go-kr-text

.if !defined(GO_KR_TEXT_BUILDLINK3_MK)
GO_KR_TEXT_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-kr-text=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-kr-text?=	build

BUILDLINK_API_DEPENDS.go-kr-text+=	go-kr-text>=0.2.0
BUILDLINK_PKGSRCDIR.go-kr-text?=	../../textproc/go-kr-text

.include "../../devel/go-pty/buildlink3.mk"
.endif	# GO_KR_TEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-kr-text
