# $NetBSD: buildlink3.mk,v 1.1 2013/04/03 10:51:46 markd Exp $

BUILDLINK_TREE+=	nepomuk-core

.if !defined(NEPOMUK_CORE_BUILDLINK3_MK)
NEPOMUK_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nepomuk-core+=	nepomuk-core>=4.10.1
BUILDLINK_PKGSRCDIR.nepomuk-core?=	../../misc/nepomuk-core

.endif	# NEPOMUK_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-nepomuk-core
