# $NetBSD: buildlink3.mk,v 1.3 2006/04/10 14:58:48 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBDFUI_BUILDLINK3_MK:=	${LIBDFUI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libdfui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibdfui}
BUILDLINK_PACKAGES+=	libdfui

.if !empty(LIBDFUI_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libdfui+=	libdfui>=4.1
BUILDLINK_PKGSRCDIR.libdfui?=	../../devel/libdfui
.endif	# LIBDFUI_BUILDLINK3_MK

.include "../../wip/libaura/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
