# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/02/09 05:41:36 xtraeme Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBDFUI_BUILDLINK3_MK:=	${LIBDFUI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libdfui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibdfui}
BUILDLINK_PACKAGES+=	libdfui

.if !empty(LIBDFUI_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libdfui+=	libdfui>=3.0
BUILDLINK_PKGSRCDIR.libdfui?=	../../devel/libdfui
.endif	# LIBDFUI_BUILDLINK3_MK

.include "../../devel/libaura/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
