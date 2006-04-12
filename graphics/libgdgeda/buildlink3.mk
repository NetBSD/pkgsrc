# $NetBSD: buildlink3.mk,v 1.6 2006/04/12 10:27:18 rillig Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGDGEDA_BUILDLINK3_MK:=	${LIBGDGEDA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgdgeda
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgdgeda}
BUILDLINK_PACKAGES+=	libgdgeda

.if !empty(LIBGDGEDA_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libgdgeda+=	libgdgeda>=2.0.15
BUILDLINK_ABI_DEPENDS.libgdgeda+=	libgdgeda>=2.0.15nb2
BUILDLINK_PKGSRCDIR.libgdgeda?=	../../graphics/libgdgeda
.endif	# LIBGDGEDA_BUILDLINK3_MK

.include "../../graphics/png/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
