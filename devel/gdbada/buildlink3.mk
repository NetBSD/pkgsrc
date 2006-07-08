# $NetBSD: buildlink3.mk,v 1.7 2006/07/08 23:10:42 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GDBADA_BUILDLINK3_MK:=	${GDBADA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gdbada
.endif

BUILDLINK_PACKAGES:=		${BUILDLINK_PACKAGES:Ngdbada} gdbada

.if !empty(GDBADA_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		gdbada
BUILDLINK_ORDER:=		${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gdbada
BUILDLINK_API_DEPENDS.gdbada+=	gdbada>=5.3
BUILDLINK_ABI_DEPENDS.gdbada+=	gdbada>=6.3nb1
BUILDLINK_PKGSRCDIR.gdbada?=	../../devel/gdbada

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif	# GDBADA_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
