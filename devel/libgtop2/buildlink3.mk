# $NetBSD: buildlink3.mk,v 1.1 2004/02/10 02:09:02 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libgtop2.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGTOP2_BUILDLINK3_MK:=	${LIBGTOP2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgtop2
.endif

.if !empty(LIBGTOP2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libgtop2
BUILDLINK_DEPENDS.libgtop2?=		libgtop2>=2.0.8
BUILDLINK_PKGSRCDIR.libgtop2?=		../../devel/libgtop2

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.endif # LIBGTOP2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
