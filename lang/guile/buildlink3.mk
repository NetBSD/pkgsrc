# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:36 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GUILE_BUILDLINK3_MK:=	${GUILE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	guile
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nguile}
BUILDLINK_PACKAGES+=	guile

.if !empty(GUILE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.guile+=	guile>=1.6.3nb1
BUILDLINK_PKGSRCDIR.guile?=	../../lang/guile

.include "../../devel/libtool/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"

.endif	# GUILE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
