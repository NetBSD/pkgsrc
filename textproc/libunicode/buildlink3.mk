# $NetBSD: buildlink3.mk,v 1.1 2004/02/20 12:48:07 jmmv Exp $
#
# This Makefile fragment is included by packages that use libunicode.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBUNICODE_BUILDLINK3_MK:=	${LIBUNICODE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libunicode
.endif

.if !empty(LIBUNICODE_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libunicode
BUILDLINK_DEPENDS.libunicode+=		libunicode>=0.4
BUILDLINK_PKGSRCDIR.libunicode?=	../../textproc/libunicode

.endif # LIBUNICODE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
