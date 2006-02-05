# $NetBSD: buildlink3.mk,v 1.5 2006/02/05 23:09:45 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GUILE14_BUILDLINK3_MK:=	${GUILE14_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	guile14
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nguile14}
BUILDLINK_PACKAGES+=	guile14

.if !empty(GUILE14_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.guile14+=	guile14>=1.4.1nb4
BUILDLINK_RECOMMENDED.guile14+=	guile14>=1.4.1nb8
BUILDLINK_PKGSRCDIR.guile14?=	../../lang/guile14

BUILDLINK_PASSTHRU_DIRS=	${LOCALBASE}/guile/1.4
BUILDLINK_FILES.guile14+=	guile/1.4/bin/*
BUILDLINK_TRANSFORM.guile14+=	-e s,/guile/1.4/bin/,/bin/,

GUILE14_SUBDIR=			guile/1.4
.endif	# GUILE14_BUILDLINK3_MK

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
