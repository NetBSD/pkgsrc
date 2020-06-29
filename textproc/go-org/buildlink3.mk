# $NetBSD: buildlink3.mk,v 1.1 2020/06/29 12:56:03 nikita Exp $

BUILDLINK_TREE+=	go-org

.if !defined(GO_ORG_BUILDLINK3_MK)
GO_ORG_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-org=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-org?=		build

BUILDLINK_API_DEPENDS.go-org+=		go-org>=1.1.0
BUILDLINK_PKGSRCDIR.go-org?=		../../textproc/go-org

.include "../../net/go-net/buildlink3.mk"
.include "../../textproc/go-chroma/buildlink3.mk"
.endif	# GO_ORG_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-org
