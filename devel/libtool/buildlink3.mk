# $NetBSD: buildlink3.mk,v 1.2 2004/02/11 04:23:35 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libtool.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LTDL_BUILDLINK3_MK:=	${LTDL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ltdl
.endif

.if !empty(LTDL_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			ltdl
BUILDLINK_DEPENDS.ltdl+=		libtool-base>=1.5.2
BUILDLINK_PKGSRCDIR.ltdl?=		../../devel/libtool-base

.endif # LTDL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
