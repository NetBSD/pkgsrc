# $NetBSD: buildlink3.mk,v 1.20 2012/03/11 03:59:27 ryoon Exp $

BUILDLINK_TREE+=	nspr

.if !defined(NSPR_BUILDLINK3_MK)
NSPR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nspr+=	nspr>=4.9.2beta1
BUILDLINK_ABI_DEPENDS.nspr?=	nspr>=4.9.2beta1
BUILDLINK_PKGSRCDIR.nspr?=	../../devel/nspr

BUILDLINK_FILES.nspr+=          lib/nspr/*
BUILDLINK_FILES.nspr+=          include/nspr/*

BUILDLINK_LIBDIRS.nspr+=	lib/nspr
BUILDLINK_RPATHDIRS.nspr+=	lib/nspr

BUILDLINK_INCDIRS.nspr+=	include/nspr

.endif	# NSPR_BUILDLINK3_MK

BUILDLINK_TREE+=	-nspr
