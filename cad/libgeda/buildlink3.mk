# $NetBSD: buildlink3.mk,v 1.3 2004/03/05 19:25:08 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGEDA_BUILDLINK3_MK:=	${LIBGEDA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgeda
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgeda}
BUILDLINK_PACKAGES+=	libgeda

.if !empty(LIBGEDA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgeda+=	libgeda-20040111{,nb[0-9]*}
BUILDLINK_PKGSRCDIR.libgeda?=	../../cad/libgeda

.include "../../devel/libstroke/buildlink3.mk"
.include "../../graphics/libgdgeda/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif	# LIBGEDA_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
