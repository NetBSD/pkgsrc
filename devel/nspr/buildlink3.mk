# $NetBSD: buildlink3.mk,v 1.16 2011/04/26 14:19:39 tnn Exp $

BUILDLINK_TREE+=	nspr

.if !defined(NSPR_BUILDLINK3_MK)
NSPR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nspr+=	nspr>=4.8.7
BUILDLINK_PKGSRCDIR.nspr?=	../../devel/nspr

BUILDLINK_FILES.nspr+=          lib/nspr/*
BUILDLINK_FILES.nspr+=          include/nspr/*

BUILDLINK_LIBDIRS.nspr+=	lib/nspr
BUILDLINK_RPATHDIRS.nspr+=	lib/nspr

BUILDLINK_INCDIRS.nspr+=	include/nspr

BUILDLINK_LDFLAGS.nspr+=	-lnspr4

.endif	# NSPR_BUILDLINK3_MK

BUILDLINK_TREE+=	-nspr
