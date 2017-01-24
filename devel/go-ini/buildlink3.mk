# $NetBSD: buildlink3.mk,v 1.1 2017/01/24 17:20:19 bsiegert Exp $

BUILDLINK_TREE+=	go-ini

.if !defined(GO_INI_BUILDLINK3_MK)
GO_INI_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-ini=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-ini?=		build

BUILDLINK_API_DEPENDS.go-ini+=	go-ini>=1.19.1
BUILDLINK_PKGSRCDIR.go-ini?=	../../devel/go-ini

.endif	# GO_INI_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-ini
