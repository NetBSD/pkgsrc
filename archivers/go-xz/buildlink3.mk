# $NetBSD: buildlink3.mk,v 1.1 2018/06/18 20:46:47 minskim Exp $

BUILDLINK_TREE+=	go-xz

.if !defined(GO_XZ_BUILDLINK3_MK)
GO_XZ_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-xz=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-xz?=		build

BUILDLINK_API_DEPENDS.go-xz+=	go-xz>=0.5.4
BUILDLINK_PKGSRCDIR.go-xz?=	../../archivers/go-xz
.endif	# GO_XZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-xz
