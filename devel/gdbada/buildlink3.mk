# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:13:27 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GDBADA_BUILDLINK3_MK:=	${GDBADA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gdbada
.endif

.if !empty(GDBADA_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		gdbada
BUILDLINK_DEPENDS.gdbada+=	gdbada>=5.3
BUILDLINK_RECOMMENDED.gdbada+=	gdbada>=5.3nb1
BUILDLINK_PKGSRCDIR.gdbada?=	../../devel/gdbada

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif	# GDBADA_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
