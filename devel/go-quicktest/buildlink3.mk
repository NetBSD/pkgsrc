# $NetBSD: buildlink3.mk,v 1.1 2020/06/29 13:35:12 nikita Exp $

BUILDLINK_TREE+=	go-quicktest

.if !defined(GO_QUICKTEST_BUILDLINK3_MK)
GO_QUICKTEST_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-quicktest=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-quicktest?=	build

BUILDLINK_API_DEPENDS.go-quicktest+=	go-quicktest>=1.10.0
BUILDLINK_PKGSRCDIR.go-quicktest?=	../../devel/go-quicktest

.include "../../devel/go-kr-pretty/buildlink3.mk"
.include "../../devel/go-cmp/buildlink3.mk"
.endif	# GO_QUICKTEST_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-quicktest
