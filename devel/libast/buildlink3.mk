# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 06:02:52 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libast.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBAST_BUILDLINK3_MK:=	${LIBAST_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libast
.endif

.if !empty(LIBAST_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libast
BUILDLINK_DEPENDS.libast+=		libast>=0.5nb5
BUILDLINK_PKGSRCDIR.libast?=		../../devel/libast

.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"

.endif # LIBAST_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
