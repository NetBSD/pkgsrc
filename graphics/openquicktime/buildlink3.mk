# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 08:55:58 xtraeme Exp $
#
# This Makefile fragment is included by packages that use openquicktime.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OPENQUICKTIME_BUILDLINK3_MK:=	${OPENQUICKTIME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	openquicktime
.endif

.if !empty(OPENQUICKTIME_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			openquicktime
BUILDLINK_DEPENDS.openquicktime+=		openquicktime>=1.0nb2
BUILDLINK_PKGSRCDIR.openquicktime?=		../../graphics/openquicktime

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

.endif # OPENQUICKTIME_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
