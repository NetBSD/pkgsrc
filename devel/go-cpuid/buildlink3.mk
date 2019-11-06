# $NetBSD: buildlink3.mk,v 1.1 2019/11/06 11:08:14 ng0 Exp $

BUILDLINK_TREE+=	go-cpuid

.if !defined(GO_CPUID_BUILDLINK3_MK)
GO_CPUID_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-cpuid=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-cpuid?=		build

BUILDLINK_API_DEPENDS.go-cpuid+=	go-cpuid>=1.2.1
BUILDLINK_PKGSRCDIR.go-cpuid?=		../../devel/go-cpuid
.endif	# GO_CPUID_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-cpuid
