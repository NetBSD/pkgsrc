# $NetBSD: buildlink3.mk,v 1.2 2004/02/26 09:24:01 adam Exp $
#
# This Makefile fragment is included by packages that use libtlen.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBTLEN_BUILDLINK3_MK:=	${LIBTLEN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libtlen
.endif

.if !empty(LIBTLEN_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libtlen
BUILDLINK_DEPENDS.libtlen+=		libtlen>=20040212
BUILDLINK_PKGSRCDIR.libtlen?=		../../chat/libtlen

.endif # LIBTLEN_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
