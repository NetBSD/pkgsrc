# $NetBSD: buildlink3.mk,v 1.10 2006/07/08 22:39:22 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GUILE_BUILDLINK3_MK:=	${GUILE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	guile
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nguile}
BUILDLINK_PACKAGES+=	guile
BUILDLINK_ORDER+=	guile

.if !empty(GUILE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.guile+=	guile>=1.6.3nb1
BUILDLINK_ABI_DEPENDS.guile+=	guile>=1.6.7nb3
BUILDLINK_PKGSRCDIR.guile?=	../../lang/guile
.endif	# GUILE_BUILDLINK3_MK

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
