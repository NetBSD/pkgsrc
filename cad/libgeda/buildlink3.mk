# $NetBSD: buildlink3.mk,v 1.20 2006/09/10 19:47:54 dmcmahill Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGEDA_BUILDLINK3_MK:=	${LIBGEDA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgeda
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgeda}
BUILDLINK_PACKAGES+=	libgeda
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libgeda

.if !empty(LIBGEDA_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libgeda+=	libgeda-20060906{,nb[0-9]*}
BUILDLINK_ABI_DEPENDS.libgeda?=	libgeda>=20060906
BUILDLINK_PKGSRCDIR.libgeda?=	../../cad/libgeda
.endif	# LIBGEDA_BUILDLINK3_MK

.include "../../graphics/libgdgeda/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
