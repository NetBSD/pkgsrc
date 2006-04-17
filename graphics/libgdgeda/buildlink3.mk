# $NetBSD: buildlink3.mk,v 1.7 2006/04/17 13:46:00 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGDGEDA_BUILDLINK3_MK:=	${LIBGDGEDA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgdgeda
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgdgeda}
BUILDLINK_PACKAGES+=	libgdgeda

.if !empty(LIBGDGEDA_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libgdgeda+=	libgdgeda>=2.0.15
BUILDLINK_ABI_DEPENDS.libgdgeda+=	libgdgeda>=2.0.15nb3
BUILDLINK_PKGSRCDIR.libgdgeda?=	../../graphics/libgdgeda
.endif	# LIBGDGEDA_BUILDLINK3_MK

.include "../../graphics/png/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
