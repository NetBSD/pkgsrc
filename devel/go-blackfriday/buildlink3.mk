# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:12 jperkin Exp $

BUILDLINK_TREE+=	go-blackfriday

.if !defined(GO_BLACKFRIDAY_BUILDLINK3_MK)
GO_BLACKFRIDAY_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-blackfriday=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-blackfriday?=		build

BUILDLINK_API_DEPENDS.go-blackfriday+=		go-blackfriday>=1.4
BUILDLINK_PKGSRCDIR.go-blackfriday?=		../../devel/go-blackfriday

.include "../../devel/go-sanitized_anchor_name/buildlink3.mk"
.endif  # GO_BLACKFRIDAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-blackfriday
