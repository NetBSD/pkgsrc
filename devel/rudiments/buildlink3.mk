# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:29 joerg Exp $
#
# This Makefile fragment is included by packages that use rudiments.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_TREE+=	rudiments

.if !defined(RUDIMENTS_BUILDLINK3_MK)
RUDIMENTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rudiments+=		rudiments>=0.25.1
BUILDLINK_ABI_DEPENDS.rudiments+=	rudiments>=0.28.2nb1
BUILDLINK_PKGSRCDIR.rudiments?=		../../devel/rudiments
.endif # RUDIMENTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-rudiments
