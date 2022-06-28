# $NetBSD: buildlink3.mk,v 1.27 2022/06/28 11:31:49 wiz Exp $

BUILDLINK_TREE+=	nspr

.if !defined(NSPR_BUILDLINK3_MK)
NSPR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nspr+=	nspr>=4.9.3.2
BUILDLINK_ABI_DEPENDS.nspr?=	nspr>=4.34nb1
BUILDLINK_PKGSRCDIR.nspr?=	../../devel/nspr

BUILDLINK_LIBDIRS.nspr+=	lib/nspr
BUILDLINK_RPATHDIRS.nspr+=	lib/nspr
BUILDLINK_INCDIRS.nspr+=	include/nspr

.endif	# NSPR_BUILDLINK3_MK

BUILDLINK_TREE+=	-nspr
