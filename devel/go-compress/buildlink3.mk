# $NetBSD: buildlink3.mk,v 1.1 2019/11/06 12:15:25 ng0 Exp $

BUILDLINK_TREE+=	go-compress

.if !defined(GO_COMPRESS_BUILDLINK3_MK)
GO_COMPRESS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-compress=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-compress?=	build

BUILDLINK_API_DEPENDS.go-compress+=	go-compress>=1.5.0
BUILDLINK_PKGSRCDIR.go-compress?=	../../devel/go-compress

.include "../../devel/go-cpuid/buildlink3.mk"
.include "../../security/go-xxhash/buildlink3.mk"
.endif	# GO_COMPRESS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-compress
