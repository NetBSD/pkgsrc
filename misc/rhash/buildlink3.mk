# $NetBSD: buildlink3.mk,v 1.1 2014/04/18 21:21:30 wiz Exp $

BUILDLINK_TREE+=	rhash

.if !defined(RHASH_BUILDLINK3_MK)
RHASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rhash+=	rhash>=1.3.1
BUILDLINK_PKGSRCDIR.rhash?=	../../misc/rhash

BUILDLINK_DEPMETHOD.rhash?=	build
.endif	# RHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-rhash
