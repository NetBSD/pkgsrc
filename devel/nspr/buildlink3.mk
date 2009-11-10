# $NetBSD: buildlink3.mk,v 1.11 2009/11/10 16:44:06 tnn Exp $

BUILDLINK_TREE+=	nspr

.if !defined(NSPR_BUILDLINK3_MK)
NSPR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nspr+=	nspr>=4.8.2.5
BUILDLINK_PKGSRCDIR.nspr?=	../../devel/nspr

BUILDLINK_FILES.nspr+=          lib/nspr/*
BUILDLINK_FILES.nspr+=          include/nspr/*

BUILDLINK_INCDIRS.nspr+=        include/nspr
BUILDLINK_LIBDIRS.nspr+=        lib/nspr
BUILDLINK_RPATHDIRS.nspr+=      lib/nspr
.endif	# NSPR_BUILDLINK3_MK

BUILDLINK_TREE+=	-nspr
