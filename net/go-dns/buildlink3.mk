# $NetBSD: buildlink3.mk,v 1.1 2016/09/04 19:29:32 bsiegert Exp $

BUILDLINK_TREE+=	go-dns

.if !defined(GO_DNS_BUILDLINK3_MK)
GO_DNS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-dns=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-dns?=		build

BUILDLINK_API_DEPENDS.go-dns+=	go-dns>=0.0.20160614nb1
BUILDLINK_PKGSRCDIR.go-dns?=	../../net/go-dns
.endif	# GO_DNS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-dns
