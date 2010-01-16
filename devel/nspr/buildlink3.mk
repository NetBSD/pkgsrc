# $NetBSD: buildlink3.mk,v 1.12 2010/01/16 13:38:08 tnn Exp $

BUILDLINK_TREE+=	nspr

.if !defined(NSPR_BUILDLINK3_MK)
NSPR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nspr+=	nspr>=4.8.2.5
BUILDLINK_PKGSRCDIR.nspr?=	../../devel/nspr

BUILDLINK_FILES.nspr+=          lib/nspr/*
BUILDLINK_FILES.nspr+=          include/nspr/*

.endif	# NSPR_BUILDLINK3_MK

BUILDLINK_TREE+=	-nspr
