# $NetBSD: buildlink3.mk,v 1.6 2006/05/25 09:17:27 rillig Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
OPENQUICKTIME_BUILDLINK3_MK:=	${OPENQUICKTIME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	openquicktime
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopenquicktime}
BUILDLINK_PACKAGES+=	openquicktime

.if !empty(OPENQUICKTIME_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.openquicktime+=	openquicktime>=1.0nb2
BUILDLINK_ABI_DEPENDS.openquicktime?=	openquicktime>=1.0nb4
BUILDLINK_PKGSRCDIR.openquicktime?=	../../multimedia/openquicktime
.endif	# OPENQUICKTIME_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
