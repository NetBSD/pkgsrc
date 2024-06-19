# $NetBSD: buildlink3.mk,v 1.7 2024/06/19 18:59:46 schmonz Exp $

BUILDLINK_TREE+=	s6-dns

.if !defined(S6_DNS_BUILDLINK3_MK)
S6_DNS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.s6-dns+=	s6-dns>=2.3.7.2
BUILDLINK_PKGSRCDIR.s6-dns?=	../../net/s6-dns
BUILDLINK_INCDIRS.s6-dns+=	include/s6-dns
BUILDLINK_LIBDIRS.s6-dns+=	lib/s6-dns
BUILDLINK_DEPMETHOD.s6-dns?=	build
.endif	# S6_DNS_BUILDLINK3_MK

BUILDLINK_TREE+=	-s6-dns
