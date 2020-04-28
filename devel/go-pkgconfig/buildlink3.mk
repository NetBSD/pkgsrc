# $NetBSD: buildlink3.mk,v 1.1 2020/04/28 13:28:04 nikita Exp $

BUILDLINK_TREE+=	go-pkgconfig

.if !defined(GO_PKGCONFIG_BUILDLINK3_MK)
GO_PKGCONFIG_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-pkgconfig=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-pkgconfig?=	build

BUILDLINK_API_DEPENDS.go-pkgconfig+=	go-pkgconfig>=0.0.0.20170226
BUILDLINK_PKGSRCDIR.go-pkgconfig?=	../../devel/go-pkgconfig
.endif	# GO_PKGCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-pkgconfig
