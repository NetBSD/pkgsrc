# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/06/03 11:16:42 shannonjr Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GDBADA_BUILDLINK3_MK:=	${GDBADA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gdbada
.endif

.if !empty(GDBADA_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		gdbada
BUILDLINK_DEPENDS.gdbada+=	gdbada>=5.3
BUILDLINK_PKGSRCDIR.gdbada?=	../../devel/gdbada

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif	# GDBADA_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
