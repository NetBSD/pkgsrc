# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/03/06 11:09:44 jmmv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
OPENQUICKTIME_BUILDLINK3_MK:=	${OPENQUICKTIME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	openquicktime
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopenquicktime}
BUILDLINK_PACKAGES+=	openquicktime

.if !empty(OPENQUICKTIME_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.openquicktime+=	openquicktime>=1.0nb2
BUILDLINK_PKGSRCDIR.openquicktime?=	../../multimedia/openquicktime

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

.endif	# OPENQUICKTIME_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
