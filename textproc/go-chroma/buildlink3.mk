# $NetBSD: buildlink3.mk,v 1.2 2020/06/24 22:58:07 nikita Exp $

BUILDLINK_TREE+=	go-chroma

.if !defined(GO_CHROMA_BUILDLINK3_MK)
GO_CHROMA_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-chroma=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-chroma?=		build

BUILDLINK_API_DEPENDS.go-chroma+=	go-chroma>=0.5.0
BUILDLINK_PKGSRCDIR.go-chroma?=		../../textproc/go-chroma

.include "../../textproc/go-regexp2/buildlink3.mk"
.include "../../devel/go-fnmatch/buildlink3.mk"
.include "../../devel/go-colorable/buildlink3.mk"
.include "../../devel/go-kingpin.v3-unstable/buildlink3.mk"
.include "../../math/go-units/buildlink3.mk"
.include "../../devel/go-i18n/buildlink3.mk"
.endif	# GO_CHROMA_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-chroma
